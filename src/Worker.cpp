#include "Worker.h"
/*
A Worker has four states 
- READY - Ready to take a new component
- WAITING - Waiting for a matching assembling component
- BUSY - Assembling
- COMPLETE - completed assembly 
*/

//Constructors/Destructors 

Worker::Worker(){
	countdown = 0;
	componentA = 0;
	componentB = 0;
	state = ::READY;
}

Worker::Worker(const Worker& t_worker){
	countdown = t_worker.countdown;
	componentA = t_worker.componentA;
	componentB = t_worker.componentB;
	state = t_worker.state;
}

Worker::~Worker(){
	delete componentA;
	delete componentB;
}

//Accessor methods

void Worker::setComponent(Component* t_component){
	if(!componentA){
		componentA = t_component;
	}
	else{
		componentB = t_component;
	}
	state = ::WAITING;
}

Component* Worker::takeProduct(){
	Component* tempComponent = componentA;
	if(componentB){
		componentA = componentB;
		componentB = 0;
		state = ::WAITING;
	}
	else{
		componentA = 0;
		state = ::READY;
	}
	return tempComponent;
}

WorkerState Worker::getState(){
	return state;
}

//Mutator methods

bool Worker::canCombine(Component* t_component){
	if(componentA->canCombine(t_component->getType())){
		return true;
	}
	return false;
}

void Worker::assemble(){
	if(canCombine(componentB)){
		countdown = 4;
		state = ::BUSY;
	}
}

void Worker::assembleCountdown(){
	if(countdown > 0){
		--countdown;
	if(countdown == 0){
	}
		componentA->assemble(componentB);
		state = ::COMPLETE;
	}
}

void Worker::printWorker(){ //Used for testing, since this was written in a text editor.
	switch(state){
		case ::READY:
			cout << "READY ";
			break;
		case ::BUSY:
			cout << "BUSY ";
			break;
		case ::WAITING:
			cout <<  "WAITING ";
			break;
		case ::COMPLETE:
			cout << "COMPLETE ";
			break;
	}

	if(componentA){
		cout << "Component #1: ";
		componentA->printComponentType();
		cout << " ";
	}

	if(componentB){
		cout << " Component #2: ";
		componentB->printComponentType();
		cout << " ";
	}
}