//Please read README.txt for further information.
//Author - Jack L. Clements

#include <random>
#include "ConveyerBelt.h"
#include "ComponentStates.h"
//Preprocessor Direcives 
#define BELT_SIZE 3
#define RUN_CYCLES 100

//Predefine functions
Component* generateNewComponent();

//Define functions
int main(int argc, const char** argv)
{
    ConveyerBelt belt(BELT_SIZE);
    for(int i = 0; i < RUN_CYCLES; i++){
    	belt.addPart(generateNewComponent());
    	belt.run();
    }
    cout << "Items produced: " << ConveyerBelt::getP() << endl;
    cout << "Components of Type A never picked up: " << ConveyerBelt::getA() << endl;
    cout << "Components of Type B never picked up: " << ConveyerBelt::getB() << endl;
    return 0;
}


//Generates a new component of type A, B or empty.
Component* generateNewComponent(){ 
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
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