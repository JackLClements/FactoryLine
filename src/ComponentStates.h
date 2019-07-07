#ifndef COMPONENT_STATES_H
#define COMPONENT_STATES_H
namespace ComponentStates{
	enum ComponentType{A, B, P};
}

namespace WorkerStates{ //TODO - clean this up somehow
	enum WorkerState{READY, WAITING, BUSY, COMPLETE};
}
#endif