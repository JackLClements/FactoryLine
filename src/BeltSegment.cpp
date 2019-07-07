#include "BeltSegment.h"
#include "ComponentStates.h"
#include <iostream>

using namespace std;
using namespace WorkerStates;


BeltSegment::BeltSegment(Worker* t_workerA, Worker* t_workerB, int t_id){
	workers.push_back(t_workerA);
	workers.push_back(t_workerB);
	nextSegment = nullptr;
	component = nullptr;
	id = t_id;
}

BeltSegment::BeltSegment(){
	nextSegment = 0;
	component = 0;
	id = 0;
}

BeltSegment::~BeltSegment(){
	delete component;
}

void BeltSegment::setNextSegment(BeltSegment *next){
	nextSegment = next;
}

void BeltSegment::setComponent(Component *component2){
	component = component2;
}

/*

IF A BELT SEGMENT HAS A COMPONENT ON IT
- IF WORKER A HAS A COMPONENT ALREADY
-- TEST IF THEY CAN BEGIN ASSEMBLY
--- ASSEMBLE, CLEAR BELT
-- ELSE, TEST  TO WORKER B
-- TEST IF WORKER B HAS A COMPONENT ALREADY
- GIVE TO WORKER A

- For each worker 
-- Do I need it?
-- Can I take it?
-- If neither, pass it to the next worker
-- This makes the assumption that ordering takes total precedence, then collection takes precedence over completion
-- We could make this multi-threaded by locking on belt access, thus making it first-come, first-served

For each belt segment
- Is there something here? Proceed to worker logic
- Is this empty? Proceed to pick up logic
- This will likely lead to a lot of instances of workers being unable to put down an object
*/

void BeltSegment::roll(){
	if(nextSegment){ //roll next part first? essentially we do the work on the way up?
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
						workers.at(i)->assemble(component);
						component = 0;
						hasMoved = true;
					}
					break;
				case ::BUSY : //BUSY - Assembling, cannot put or take
					workers.at(i)->assembleCountdown();
					break;
				case ::COMPLETE : //COMPLETE - completed assembly
					if(!component && !hasMoved){
						component = workers.at(i)->getProduct();
						hasMoved = true;
					}
					break;
		}
	}
	if(!nextSegment){
		if(component){
			cout << "Rolled off the line - " << component->getType() << endl;
		}
		else{
			cout << "Nothing rolled off the line." << endl;
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

void BeltSegment::addWorker(Worker* worker){
	workers.push_back(worker);
}



