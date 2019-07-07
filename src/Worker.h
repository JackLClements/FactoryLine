#include "Component.h"
#include "ComponentStates.h" //TODO rename
#ifndef WORKER_H
#define WORKER_H

using namespace WorkerStates;

class Worker{
private:
	int countdown;
	WorkerState state;
	Component* component; //think about memory here as you could be in trouble down the line w/pointers
	//do we want the associated conveyor position as a function pointer?
public:
	Worker();
	~Worker();
	void setComponent(Component* t_component);
	void assemble(Component* t_component);
	bool canCombine(Component* t_component);
	void assembleCountdown();
	bool hasAssembled();
	WorkerState getState();
	Component* getProduct();
};

#endif