#include <iostream>
#include "room.h"
#include "controller.h"

using namespace std;

int main() {
  Controller maze;
  
  maze.addRoom(new Room("Start", "Welcome to the maze."));
  maze.addRoom(new Room("B133 Center", "You are in the middle of the room"));
  maze.addRoom(new Room("B133 North", "You are under the screen"));
  maze.addRoom(new Room("B133 West", "You are under the clock"));
  maze.addRoom(new Room("B133 East", "You are by the window"));

  maze.addExit( maze.getAddrByID("Start"), 
                maze.getAddrByID("B133 Center"),
                "north" );
  maze.addExit( maze.getAddrByID("B133 Center"), 
                maze.getAddrByID("Start"),
                "south" );

  maze.addExit( maze.getAddrByID("B133 North"), 
                maze.getAddrByID("B133 Center"),
                "south" );
  maze.addExit( maze.getAddrByID("B133 Center"), 
                maze.getAddrByID("B133 North"),
                "north" );
  //maze.printAllRooms();
  maze.setCurrentRoom( maze.getAddrByID("Start") );

  while (1)
    {
      maze.printCurrent();
      maze.handleInput();
    }
  
  cout << "Program ended.  Bye." << endl;
  return 0;
}
