#include <iostream>
#include <iomanip>
#include<bits/stdc++.h>
#include "controller.h"

using namespace std;

void Controller::addRoom(Room* rptr) {
  string newID = rptr->getID();
  if ( !getRoomByID(newID) )
  {
    rooms_.push_back(rptr); 
    roomsID_[newID] = rptr;
  }
  else 
  {
    errorQuit("Duplicate room id = [" + newID + "]");
  }
}

void Controller::errorQuit(string message)
{
  cerr << "***************************************" << endl;
  cerr << message << endl;
  cerr << "***************************************" << endl;
  exit(1);
}


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

  /// make inputBuffer all lowercase
  transform(inputBuffer.begin(), inputBuffer.end(), 
            inputBuffer.begin(), ::tolower);  

  if (isHelp(inputBuffer))
    printHelp();
  else if (isDirection(inputBuffer))
    moveRoom(inputBuffer);
  else if (inputBuffer == "jump")
    cout << "Whee!" << endl;
  else if (inputBuffer == "look")
    printCurrent();
  else if (inputBuffer == "quit")
    shutDown();
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
    currentRoom_->setVisited();
  }
  else
  {
    cout << "You can't go " << dir << endl;
  }
}

void Controller::addExitByID(string from, string to, string dir)
{
  Room* fromPtr = getAddrByID(from);
  Room* toPtr = getAddrByID(to);
  if (fromPtr && toPtr)
  {
    addExit(fromPtr, toPtr, dir);
  }
  else
  {
    if (!fromPtr)
       errorQuit("Invalid ID [" + from + "]");
    else
       errorQuit("Invalid ID [" + to + "]");

  }
}

bool Controller::isHelp(string str)
{
  if (str == "h" || str == "help")
    return true;
  return false;
}

void Controller::printHelp()
{
  cout << "       Commands (so far):" << endl;
  cout << "=================================" << endl;
  cout << endl;
  cout << "h or help ....... this screen" << endl;
  cout << "n or north ...... move north" << endl;
  cout << "s or south ...... move south" << endl;
  cout << "e or east ....... move east" << endl;
  cout << "w or west ....... move west" << endl;
  cout << "u or up ......... move up" << endl;
  cout << "jump ............ exercise" << endl;
  cout << "look ............ look around you" << endl;
  cout << "quit ............ get on with RL" << endl;
  cout << "=================================" << endl;
  cout << endl << endl;
}

void Controller::shutDown()
{
  int roomCount = 0;
  for (int i=0;i<rooms_.size();i++)
    if (rooms_[i]->visited())
      roomCount ++;
  cout << "You visited " << roomCount 
       << " of " << rooms_.size() << " total rooms" 
       << endl;
  exit(0);     
}