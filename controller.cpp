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

void Controller::addRoom(string roomID, string desc) {
  if ( !getRoomByID(roomID) )
  {
    Room* rptr = new Room(roomID, desc);
    rooms_.push_back(rptr); 
    roomsID_[roomID] = rptr;
  }
  else 
  {
    errorQuit("Duplicate room id = [" + roomID + "]");
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
  commands_ ++;
  if (isHelp(inputBuffer))
    printHelp();
  else if (isDirection(inputBuffer))
    moveRoom(inputBuffer);
  else if (inputBuffer == "jump")
    cout << "Whee!" << endl;
  else if (inputBuffer == "look")
    currentRoom_->look();
  else if (inputBuffer == "quit")
    shutDown();
  else if (inputBuffer == "i")
    printInventory();
  else if (inputBuffer == "inventory")
    printInventory();
  else if (inputBuffer == "score")
    printScore();
  else if (inputBuffer.substr(0, 3) == "get")
    pickup(inputBuffer.substr(4));
  else if (inputBuffer.substr(0, 4) == "drop")
    drop(inputBuffer.substr(5));
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
  if (dir == "down") 
  {
    return true;
  }
  if (dir == "d") 
  {
    dir = "down";
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
    if (dir == "up") currentLevel_ --;
    if (dir == "down") currentLevel_ ++;
  }
  else
  {
    cout << "You can't go " << dir << endl;
  }
}

void Controller::addExit(string from, string to, string dir)
{
  Room* fromPtr = getRoomByID(from);
  Room* toPtr = getRoomByID(to);
  if (fromPtr && toPtr)
  {
    fromPtr->setExit(dir, toPtr);
  }
  else
  {
    if (!fromPtr)
       errorQuit("Can't add exit: Invalid ID [" + from + "]");
    else
       errorQuit("Can't add exit: Invalid ID [" + to + "]");

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
  cout << "u or up ......... move up a level" << endl;
  cout << "d or down  ...... move down a level" << endl;
  cout << "i or inventory... show what you have" << endl;
  cout << "get [item] ...... pick up the item" << endl;
  cout << "drop [item] ..... put down the item" << endl;
  cout << "jump ............ exercise" << endl;
  cout << "look ............ look around you" << endl;
  cout << "score ........... see how you're doing" << endl;
  cout << "quit ............ get on with RL" << endl;
  cout << "=================================" << endl;
  cout << endl << endl;
}

void Controller::shutDown()
{
  printScore();
  exit(0);     
}

void Controller::printScore()
{
  cout << "You used " << commands_ << " commands." << endl;
  int roomCount = 0;
  for (int i=0;i<rooms_.size();i++)
    if (rooms_[i]->visited())
      roomCount ++;
  cout << "You visited " << roomCount 
       << " of " << rooms_.size() << " total rooms." 
       << endl;
  int heldCount = 0;
  for (int i=0;i<things_.size();i++)
    if (things_[i]->held())
      heldCount ++;
  cout << "You held " << heldCount 
       << " of " << things_.size() << " total things." 
       << endl;
}

void Controller::addThing(string roomID, string thingID) 
{
  if ( !getThingByID(thingID) )
 {
    Thing* newThing = new Thing(thingID);
    things_.push_back( newThing ); 
    thingsID_[thingID] = newThing;
    getRoomByID(roomID)->addThing( newThing );
  }
  else 
  {
    errorQuit("Duplicate thing = [" + thingID + "]");
  }
}

void Controller::pickup(string thingID)
{
  Thing* tptr = getThingByID(thingID);
  if (tptr)
  {
    if (currentRoom_->removeThing( tptr ) )
    {
      inventory_.push_back( tptr );
      tptr->setHeld();
      cout << "You are now holding a(n) " << thingID << endl;
    }
    else
    {
      cout << "I don't see a(n) " << thingID << " here." << endl;
    }
  }
  else 
  {
    cout << "I don't know what a(n) " << thingID << " is." << endl;
  }
}

void Controller::drop(string thingID)
{
  Thing* tptr = getThingByID(thingID);
  if (tptr)
  {
    auto pos = find(inventory_.begin(), inventory_.end(), tptr);
    if (pos == inventory_.end())
    {
      cout << ("You don't have a(n) " + tptr->getID()) << endl;
    }
    else 
    {
      currentRoom_->addThing( tptr );
      inventory_.erase(pos);
      cout << "You dropped a(n)" << thingID << endl;
    }
  }
  else
  {
    cout << "I don't know what a(n) " << thingID << " is." << endl;
  }
}

void Controller::printInventory()
{
  cout << "You are holding:" << endl;
  for (Thing* i: inventory_)
  {
    cout << "- " << i->getID() << endl;
  }
}

Thing* Controller::getThingByID(string thingID)
{
  auto pos = thingsID_.find(thingID);
  if (pos == thingsID_.end()) 
    return nullptr; 
  return thingsID_[thingID];
}