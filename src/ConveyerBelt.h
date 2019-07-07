#include "BeltSegment.h"

#ifndef CONVEYER_BELT_H
#define CONVEYER_BELT_H

class ConveyerBelt{
private:
	int size; 
	BeltSegment* start;
	static int countA;
	static int countB;
	static int countP;
public:
	//Constructors/Destructors
	ConveyerBelt(int t_size); //generates a whole belt
	ConveyerBelt(int t_size, BeltSegment* t_belt); //make a belt from one or more segments
	ConveyerBelt(const ConveyerBelt& t_conveyerBelt);
	~ConveyerBelt();
	//Accessor methods
	int getSize();
	//Mutator methods
	void run();
	void addPart(Component* t_part);

	//Static methods
	static void addA();
	static int getA();
	static void addB();
	static int getB();
	static void addP();
	static int getP();
};

#endif