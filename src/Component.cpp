#import "Component.h"

Component::Component(){
	type = ::A;
}

Component::Component(Component& component){
	this->type = component.getType();
}

Component::~Component(){

}

Component::Component(ComponentType type){
	this->type = type;
}

ComponentType Component::getType(){
	return this->type;
}

bool Component::canCombine(ComponentType type){
	/*
	if(component->getType() != this->type && component->getType() != ::P){
		//delete other component...
		this->type = ::P;
	}*/
	if(type != this->type && type != ::P){ //assumption that we cannot extend for further logic
		return true;
	}
	return false;
}

bool Component::isComplete(){
	if(type == ::P){
		return true;
	}
	return false;
}

void Component::assemble(Component *component){
	this->type = ::P;
	component->~Component();
}