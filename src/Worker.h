#include "Component.h"
#include "ComponentStates.h"
#ifndef WORKER_H
#define WORKER_H

using namespace WorkerStates;

class Worker{
public:
	//Constructor/Destructors
	Worker();
	Worker(const Worker& t_worker);
	~Worker();
	//Accessor methods
	void setComponent(Component* t_component);
	WorkerState getState();
	Component* takeProduct();
	//Mutator methods
	void assemble();
	bool canCombine(Component* t_component);
	void assembleCountdown();
	bool hasAssembled();
	void printWorker();
private:
	int countdown;
	WorkerState state;
	Component* componentA;
	Component* componentB;
};

#endif