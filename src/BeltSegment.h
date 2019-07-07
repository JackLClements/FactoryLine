#include "Worker.h"
#include <vector>

#ifndef BELT_SEGMENT_H
#define BELT_SEGMENT_H

class BeltSegment{
	private:
		vector<Worker*> workers;
		BeltSegment* nextSegment;
		Component* component;
		int id;
	public:
		//Creators/Destructors
		BeltSegment(Worker* t_workerA, Worker* t_workerB, int t_id);
		BeltSegment();
		BeltSegment(const BeltSegment& t_beltSegment);
		~BeltSegment();
		//Accessor methods
		void setNextSegment(BeltSegment* t_next);
		void setComponent(Component* t_component);
		//Mutator Methods
		void roll(); //main logic function
		void addWorker(Worker* t_worker);
		void print();
		BeltSegment* next();
};

#endif