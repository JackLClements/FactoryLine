#include "BeltSegment.h"

class ConveyerBelt{
private:
	int size; //idk if we need this or not, can't hurt
	BeltSegment* start;
public:
	ConveyerBelt(int size); //generates a whole belt
	ConveyerBelt(int size, BeltSegment* belt); //make a belt from one or more segments
	void run();
	void runFor(int steps);
	void addPart(Component* t_part);
};