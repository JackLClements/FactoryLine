#import "Component.h"

//Constructors/Destructors

Component::Component(){
	type = ::A;
}

Component::Component(const Component& t_component){
	type = t_component.type;
}

Component::~Component(){

}

Component::Component(ComponentType t_type){
	type = t_type;
}

//Accessor methods

ComponentType Component::getType(){
	return type;
}

//Mutator methods

bool Component::canCombine(ComponentType t_type){
	if(t_type != type && t_type != ::P){ //Assumption can be changed for further logic, but remains hard-coded
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

void Component::assemble(Component *t_component){
	type = ::P;
	t_component->~Component();
}

void Component::printComponentType(){ //Used largely for testing, since this was written in a text editor.
	switch(type){
		case ::A:
			cout << "A";
			break;
		case ::B: 
			cout << "B";
			break;
		case ::P:
			cout << "Product";
			break;
	}
}