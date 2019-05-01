#include <iostream>
#include <iomanip>
#include "controller.h"

using namespace std;

void Controller::printAllRooms()
{
  for (int i=0;i<rooms_.size();i++)
    cout << setw(20) << rooms_[i]->getID() 
         << setw(40) << rooms_[i]->getDesc() 
         << endl; 
}

void Controller::printCurrent()
{
  cout << currentRoom_->getID() << endl;
  cout << endl;
  cout << currentRoom_->getDesc() << endl; 
  /// print the things
}

void Controller::handleInput()
{
  string inputBuffer;
  cout << ">";
  getline(cin, inputBuffer);

  if (isDirection(inputBuffer))
    moveRoom(inputBuffer);
  else if (inputBuffer == "jump")
    cout << "Whee!" << endl;
  else
    cout << "I don't know how to " << inputBuffer << endl;
}

bool Controller::isDirection(string& dir)
{
  if (dir == "up") 
    {
      return true;
    }
  if (dir == "u") 
    {
      dir = "up";
      return true;
    }
  if (dir == "north") 
    {
      return true;
    }
  if (dir == "n") 
    {
      dir = "north";
      return true;
    }
  if (dir == "south") 
    {
      return true;
    }
  if (dir == "s") 
    {
      dir = "south";
      return true;
    }
  if (dir == "east") 
    {
      return true;
    }
  if (dir == "e") 
    {
      dir = "east";
      return true;
    }
  if (dir == "west") 
    {
      return true;
    }
  if (dir == "w") 
    {
      dir = "west";
      return true;
    }
  return false;
}

void Controller::moveRoom(string dir)
{
  Room *nextRoom;
  nextRoom = currentRoom_->getExit(dir);
  if (nextRoom)
    {
      currentRoom_ = nextRoom;
    }
  else
    {
      cout << "You can't go " << dir << endl;
    }
}
