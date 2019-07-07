#include "Worker.h"
#include "Component.h"
#include <vector> 
using namespace std;

class BeltSegment{
	private:
		vector<Worker*> workers;
		BeltSegment* nextSegment; //need a hasNext method
		Component* component;
		int id;
	public:
		BeltSegment(Worker* t_workerA, Worker* t_workerB, int t_id);
		BeltSegment();
		~BeltSegment();
		void setNextSegment(BeltSegment* next);
		void setComponent(Component* component2);
		void roll(); //main logic function
		void addWorker(Worker* worker);
		BeltSegment* next();
};