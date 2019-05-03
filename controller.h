#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <vector>
#include <map>

#include "room.h"
#include "thing.h"

using namespace std;

class Controller
{
 public:
  Controller() {commands_=0;currentLevel_=1;}
  void addRoom(string roomID, string desc=""); // string ID version
  void addExit(string from, string to, string dir); 
  void printAllRooms();
  void printCurrent();
  void handleInput();
  void setCurrentRoom(string roomID) {currentRoom_ = getRoomByID(roomID);
                                      currentRoom_->setVisited();}
  void addThing(string roomID, string thingID);

private:
  void addRoom(Room* rptr); // depr
  Room* getRoomByID(string ID) {return roomsID_[ID];}
  void setCurrentRoom(Room* rptr) {currentRoom_ = rptr;
                                   currentRoom_->setVisited();}
  bool isDirection(string &direction);
  bool isHelp(string str);
  void printHelp();
  void shutDown();
  void moveRoom(string dir);
  void errorQuit(string messsage);
  void pickup(string thingID);
  void drop(string thingID);
  void printInventory();
  void printScore();

  Thing* getThingByID(string thingID );
  map<string, Room*> roomsID_;
  map<string, Thing*> thingsID_;
  vector<Room*> rooms_;
  Room* currentRoom_;
  vector<Thing*> things_;
  vector<Thing*> inventory_;
  int commands_;
  int currentLevel_;
};

#endif
