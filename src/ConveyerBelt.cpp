#include "ConveyerBelt.h"

//Static Variables
int ConveyerBelt::countA = 0;
int ConveyerBelt::countB = 0;
int ConveyerBelt::countP = 0;

//Constructors/Destructors

ConveyerBelt::ConveyerBelt(int t_size){ //Potential improvement - move all belt creation logic into a single loop
	size = t_size;
	Worker* workerA = new Worker();
	Worker* workerB = new Worker();
	start = new BeltSegment(workerA, workerB, 0); //create start of belt
	BeltSegment* current = start;
	for(int i = 1; i < size; i++){
		Worker* workerC = new Worker();
		Worker* workerD = new Worker();
		BeltSegment* segment2 = new BeltSegment(workerC, workerD, i); //alternative move worker setup to the belt segment class
		current->setNextSegment(segment2);
		current = segment2;
	}
}

ConveyerBelt::ConveyerBelt(int t_size, BeltSegment* t_belt){
	size = t_size;
	start = t_belt;
}

ConveyerBelt::ConveyerBelt(const ConveyerBelt& t_conveyerBelt){
	size = t_conveyerBelt.size;
	start = t_conveyerBelt.start;
}

ConveyerBelt::~ConveyerBelt(){
}

//Accessor methods
int ConveyerBelt::getSize(){
	return size;
}

//Mutator Methods

void ConveyerBelt::run(){ //Run logic for one step
	start->roll();
}

//Adds a part to the start of the conveyer belt
void ConveyerBelt::addPart(Component* t_part){
	start->setComponent(t_part);
}

//Static methods

void ConveyerBelt::addA(){
	countA++;
}

void ConveyerBelt::addB(){
	countB++;
}

void ConveyerBelt::addP(){
	countP++;
}

int ConveyerBelt::getA(){
	return countA;
}

int ConveyerBelt::getB(){
	return countB;
}

int ConveyerBelt::getP(){
	return countP;
}