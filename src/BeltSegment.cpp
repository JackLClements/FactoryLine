#include "BeltSegment.h"
#include "ConveyerBelt.h"

//Constructors/Destructors 

BeltSegment::BeltSegment(Worker* t_workerA, Worker* t_workerB, int t_id){
	workers.push_back(t_workerA);
	workers.push_back(t_workerB);
	nextSegment = 0;
	component = 0;
	id = t_id;
}

BeltSegment::BeltSegment(){
	nextSegment = 0;
	component = 0;
	id = 0;
}

//Note - copy constructor only defined here to match rule of 3, duplicating a linked list like this could cause undefined behvaiour
BeltSegment::BeltSegment(const BeltSegment& t_beltSegment){
	workers = t_beltSegment.workers;
	nextSegment = t_beltSegment.nextSegment;
	component = t_beltSegment.component;
	id = t_beltSegment.id;
}

BeltSegment::~BeltSegment(){
	delete component;
	if(nextSegment){
		delete nextSegment;
	}
}

//Accessor Methods

void BeltSegment::setNextSegment(BeltSegment *t_next){
	nextSegment = t_next;
}

void BeltSegment::setComponent(Component *t_component){
	component = t_component;
}

//Other methods

/*
* A single step of the simulation.
* Rolls the belt in front first, then iterates through workers, allowing them to take a component, assemble or put a product down
* Adds to the totals produced if the belt segment element has no further elements.
*/
void BeltSegment::roll(){
	//print();
	if(nextSegment){ //Roll each belt part first, doing the decision work on the way up to avoid clogging up the next belt segment
		nextSegment->roll();
	}
	
	bool hasMoved = false; //Single action take/put for belt segment
	for(int i = 0; i < workers.size(); i++){
		switch(workers.at(i)->getState()){
				case ::READY : //READY - Ready to take a new component
					if(component && !component->isComplete() && !hasMoved){
						workers.at(i)->setComponent(component);
						component = 0;
						hasMoved = true;
					}
					break;
				case ::WAITING : //WAITING - Waiting for a matching assembling component, will take if one is found
					if(component && workers.at(i)->canCombine(component) && !hasMoved){
						workers.at(i)->setComponent(component);
						workers.at(i)->assemble();
						component = 0;
						hasMoved = true;
					}
					break;
				case ::BUSY : //BUSY - Assembling, cannot put or take
					workers.at(i)->assembleCountdown();
					break;
				case ::COMPLETE : //COMPLETE - completed assembly
					if(!component && !hasMoved){
						component = workers.at(i)->takeProduct();
						hasMoved = true;
					}
					if(component && !component->isComplete() && !hasMoved){
						workers.at(i)->setComponent(component);
						hasMoved = true;
					}
					break;
		}
	}
	if(!nextSegment && component){
			switch(component->getType()){
				case ::A:
					ConveyerBelt::addA();
					break;
				case ::B:
					ConveyerBelt::addB();
					break;
				case ::P:
					ConveyerBelt::addP();
					break;
			}
	}
	else{
		if(component){
			nextSegment->setComponent(component);
		}
	}
}

BeltSegment* BeltSegment::next(){
	return nextSegment;
}

void BeltSegment::addWorker(Worker* t_worker){
	workers.push_back(t_worker);
}

void BeltSegment::print(){ //Used for testing, since this was written in a text editor.
	cout << "Belt Segment: " << id << " ";
	if(component){
		cout << "contains - ";
		component->printComponentType();
		cout << " ";
	}
	for(int i = 0; i < workers.size(); i++){
		cout << "Worker " << i << " is ";
		workers.at(i)->printWorker();
	}
	cout << endl;
}


