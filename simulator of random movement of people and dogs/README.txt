

This program show movement of people and dogs.
every charactermoving one of nine direction (up,down,left,right,upDown,downLeft,leftRight,upRight or dont move)
A character moving in a constant direction for 17 steps and then changes direction randomly.
If during the 17 steps the character bump into one of the walls, the character change it direction respectively.
after changing the direction that caused by hitting the wall does not affect the counting of the steps.

The simulator will hold a queue (list) of dogs and queue of person.
In each stage The simulator will remove a dog and a person and tell them to move.

The program files:
Charater.cc- this file presents a character (dog or person) and calls the header file "character.h".
character.h- this file contain a class and decleretions of functions inside Charater.cc.
Dog.cc-this file presents a Dog and calls the header file "Dog.h".
Dog.h-this file contain a class and decleretions of functions inside Dog.cc.
Person.cc-this file presents a Person and calls the header file "Person.h".
Person.h-this file contain a class and decleretions of functions inside Person.cc.
DogQueue.cc- this file presents a Queue of dogs and calls the header file "DogQueue.h".
DogQueue.h-this file contain a class and decleretions of functions inside DogQueue.cc.
PersonQueue.cc- this file presents a Queue of persons and calls the header file "PersonQueue.h".
PersonQueue.h-this file contain a class and decleretions of functions inside PersonQueue.cc.
Simulator.cc-this file presents a simulator that displays random motion of people and dogs and call the 
header file "Simulator.h".
Simulator.h-this file contain a class and decleretions of functions inside Simulator.cc.
main.cc- this file activate the entire program.

how to compile?
we create The file that unites all the files together called makefile
this file concerned to compile all the files together.
after saving each file when we write in the terminal "make"  all file will pass compiling.


how to run
you should write in the terminal ./ex3
afther you can press any keybord and the figher will move 
if you will press "esc" the progrem will end 

input:
when we try to run the line ./Ex4 we must add two numbers that presents row an call of the frame 
then the input will be "./Ex4 <Row Num> <Cols Num>".

during the program we need to press any key on the keyboard so the characters will move
in case we want to end the program we will press "Esc" key. 

output:
the output will be a gray frame size-->row and col , inside the frame we will see 2 red persons and 3 pink dogs 
when we press any key we will see one person and one dog move each iteration.