#include "Worker.h"
//FOUR STATES
//READY - Ready to take a new component
//WAITING - Waiting for a matching assembling component
//BUSY - Assembling
//COMPLETE - completed assembly 
Worker::Worker(){
	countdown = 0;
	component = 0;
	state = ::READY;
}

Worker::~Worker(){
	delete component;
}

void Worker::setComponent(Component* t_component){
	component = t_component;
	state = ::WAITING;
}

Component* Worker::getProduct(){
	return component;
}

WorkerState Worker::getState(){
	return state;
}

bool Worker::canCombine(Component* t_component){
	if(component->canCombine(t_component->getType())){
		return true;
	}
	return false;
}

void Worker::assemble(Component *t_component){
	if(canCombine(t_component)){
		countdown = 4;
		component->assemble(component);
		state = ::BUSY;
	}
}

void Worker::assembleCountdown(){
	--countdown;
	if(countdown <= 0){
		state = ::COMPLETE;
	}
}

bool Worker::hasAssembled(){ //TODO - double check logic, do we even need this now?
	if(state == ::COMPLETE){
		return true;
	}
	return false;
}

//work function