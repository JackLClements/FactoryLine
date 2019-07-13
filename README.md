## Overview

An abstracted factory line simulation written in roughly 5-6 hours in C++. I spent longer on this than I wanted to, given it was a warmup exercise, but since it's been a while since I last wrote C++ and I spent an hour configuring a make system I didn't hate, I'd call this a reasonable success.

## DESIGN DECISIONS

I have implemented the conveyer belt as a collection of linked list-like elements.
The ability of a regular linked list to implicitly know which element is next gives it an advantage over a vector.

## ASSUMPTIONS 
- that the actions of the first worker attached to any given conveyer belt segment is given priority
- that placing an object back onto the belt is given priority 
- that the conveyer belt only rolls in one direction
- that after four steps assembling a product, a worker places the product back on their assigned belt segment (if clear)
- that whilst assembling a product, the worker does not pick up a new product, as both their hands are full
- that the worker's second hand after assembling a product can only hold another component, not do any futher 
comparisons or hold a third component
- that we want the sum total of all components and items produced by all conveyer belts

## OUTPUT  
The conveyer belt using the specified RNG input appears to produce completed components generally just over 1/3rd of the time,
with components rolling off the belt continuously after 10-or-so iterations. More singular components roll off the line,
causing a backlog as workers collect and build and are waiting for free belts. Similarly, the workers towards the front
of the line assemble more completed components than those towards the end of the line, who often end up holding onto 
components for long periods of time, waiting for the matching component to arrive. The problem of the backlog is exacerbated as
the number of cycles continues, as the workers enter a state of constant building whilst new elements are generated.

I get the feeling that better results are achieveable by changing how the state switching works, but given the
time constraints, changing this could potentially be at the expense of correct behaviour.

## NOTES  
Only essential accessor functions have been implemented for the sake of time. This may not be practical in a production system.
I wanted the use of enums to be more elegant than it ended up. Since enums are simply abstracted ints, more complex behaviour like
in Java (where they act as a special type of class). More time spent on the problem would have devised a more appropriate state solution.

## POSSIBLE EXTENSIONS  
- Add a function that allows multiple workers to be added to a conveyer belt segment, rather than the two done so far 
(use of vectors already supports this to some extent)
- Allow workers to hold more than two components/products at a time using a priority queue system
- Calcualte the total produced items/untouched components on a per-conveyer belt basis via a callback function
- Make the print functions display a more comprehensible text abstraction of the simulation state (like in the example)
- Add some kind of additional mechanism to place unfinished items at the start of the belt or into some sort of queue
for the least busy workers
- Clean up the behavioural code so that each belt segment doesn't decide what each worker does, utilise a function pointer
so that the worker can return to a given belt segment instead
- Use threading to allow the workers to run in parallel according to a fixed timestep
