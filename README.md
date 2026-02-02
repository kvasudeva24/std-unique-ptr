My attempt at learning smart pointers. Starting with unique ptr first. Notes down here as I go. 

Smart pointer automate new and delete process.

Wrapper around a raw pointer
Scoped ptr (destructor)
No copy assigment or copy constructor (thats why it is unique)

Construtor is explicit 
make_unique provides exception safety (preferred)

can't pass it to function or data structure or copy it (move??)

make_unique:
a function declared outside unique_ptr (non-member function)
It creates a unique ptr itself and returns back

but it is moved when it returns back -- this is because the copy constructor is deleted so the compiler uses move instead


Other Notes:
Since T can have some n number of arguments we use typename... Args to represent some those n arguements
that could be of different types. known as a pack of types.

Args&& ... args is a pack of paramters
std::forwarding is used for perfect forwarding back to original constructor (since it cant access anything inside just call the constructor)
Only use std::forward with templates as you do not know how they were passed and cant afford 2^N variations of one function

Things to do:
See what new does and what it returns (in fail cases too)
Create the .h file 



What is the keyword new?:

New takes a lot of time because it does a lot of steps

New finds a block of memory that will hold our object and give us a pointer back to the memory address of that object

It also calls the constructor of the type

new techically returns a void* 
delete also calls the destructor
placement new takes a memory address and rerwrites bytes?? (learn more)

operator new is slightly different as that is the cpp version of malloc
keyword new returns an actual typed pointer

malloc --> aligned for largest suitable type
new --> aligned with the type you request

that is why placement new requires alignas
