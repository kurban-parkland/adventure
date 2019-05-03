/// An 80s style adventure game 
/// requires c++11 (-std=c++11)

#include <iostream>
#include "room.h"
#include "controller.h"

using namespace std;

int main() {
  Controller maze;
  
  maze.addRoom("Start", "Welcome to the maze.");
  maze.addRoom("B133 Center", "You are in the middle of the room");
  maze.addRoom("B133 North", "You are under the screen");
  maze.addRoom("B133 West", "You are under the clock");
  maze.addRoom("B133 East", "You are by the window");

  maze.addExit("Start","B133 Center","north");
  maze.addExit("B133 Center","Start","south");
  maze.addExit("B133 North","B133 Center","south");
  maze.addExit("B133 Center","B133 North","north");
  maze.addExit("B133 Center","B133 East","east");
  maze.addExit("B133 East","B133 Center","west");
  maze.addExit("B133 Center","B133 West","west");
  maze.addExit("B133 West","B133 Center","east");
  //maze.printAllRooms();
  maze.setCurrentRoom("Start");


  //lets put some things in
  maze.addThing("Start", "dry erase marker");
  maze.addThing("B133 East", "red chair");
  maze.addThing("B133 East", "blue chair");
  maze.addThing("B133 West", "paper");
  maze.addThing("B133 North", "remote control");
  maze.addThing("B133 Center", "cell phone");


  while (1)
  {
    maze.printCurrent();
    maze.handleInput();
  }
  
  cout << "Program ended.  Bye." << endl;
  return 0;
}