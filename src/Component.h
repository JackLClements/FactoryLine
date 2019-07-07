#include "ComponentStates.h"

using namespace ComponentStates;

#ifndef COMPONENT_H
#define COMPONENT_H

class Component{
public:
	Component();
	Component(Component& component);
	~Component();
	Component(ComponentType type);
	bool canCombine(ComponentType type);
	bool isComplete();
	void assemble(Component* component);
	ComponentType getType();
private:
	ComponentType type;
};

#endif