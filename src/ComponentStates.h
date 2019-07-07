#ifndef COMPONENT_STATES_H
#define COMPONENT_STATES_H
namespace ComponentStates{
	enum ComponentType{A, B, P}; //Where A and B are component types and P is completed
}

namespace WorkerStates{ 
	enum WorkerState{READY, WAITING, BUSY, COMPLETE};
}
#endif