#include "ConveyerBelt.h"
#include "Worker.h"
#include <iostream>


ConveyerBelt::ConveyerBelt(int size){
	this->size = size;
	Worker* workerA = new Worker();
	Worker* workerB = new Worker();
	start = new BeltSegment(workerA, workerB, 0);
	BeltSegment* current = start;
	for(int i = 1; i < size; i++){
		std::cout << "creating new belt " << i << std::endl;
		Worker* workerC = new Worker(); //USE NEW HERE
		Worker* workerD = new Worker();
		BeltSegment* segment2 = new BeltSegment(workerC, workerD, i); //alternative move worker setup to the belt segment class
		current->setNextSegment(segment2);
		current = segment2;
	}
}

ConveyerBelt::ConveyerBelt(int size, BeltSegment* belt){
	this->size = size;
	start = belt;
}

void ConveyerBelt::run(){
	//TODO - run logic for one step
	start->roll();
}

void ConveyerBelt::runFor(int steps){
	for(int i = 0; i < steps; i++){
		run();
	}
}

void ConveyerBelt::addPart(Component* t_part){
	start->setComponent(t_part);
}