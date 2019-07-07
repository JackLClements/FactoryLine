#include <iostream>
#include <random>
#include "ConveyerBelt.h"
#include "ComponentStates.h"

using namespace ComponentStates;

using namespace std; 

Component* generateNewComponent();

int main(int argc, const char** argv)
{
    cout << "Hello, world!" << endl;
    ConveyerBelt belt(3);
    for(int i = 0; i < 100; i++){
    	cout << "test" << endl;
    	belt.addPart(generateNewComponent());
    	belt.run();
    }
    return 0;
}

Component* generateNewComponent(){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
	uniform_int_distribution<int> distribution(0,2);

	switch(distribution(generator)){
		case 0 :
			return new Component(::A);
		case 1: 
			return new Component(::B);
		case 2:
			return 0;
		default:
			return 0; //should never occur, but my compiler shouts at me otherwise
	}
}

//DESIGN DECISIONS
/*
The ability of a regular linked list to implicitly know hwich element is next gives it an advantage over a vector

*/