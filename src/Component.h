#include "ComponentStates.h"
#include <iostream>

using namespace std;
using namespace ComponentStates;

#ifndef COMPONENT_H
#define COMPONENT_H

class Component{
public:
	//Constructors/Destructors 
	Component();
	Component(const Component& t_component);
	~Component();
	Component(ComponentType t_type);
	//Accessor methods
	ComponentType getType();
	//Mutator methods
	bool canCombine(ComponentType t_type);
	bool isComplete();
	void assemble(Component* t_component);
	void printComponentType();
private:
	ComponentType type;
};

#endif