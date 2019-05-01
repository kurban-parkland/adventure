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
  void addRoom(Room* rptr);
  void addExit(Room* from, Room* to, string dir) 
                    {   from->setExit(dir, to); }
  void addExitByID(string from, string to, string dir); 
  void printAllRooms();
  void setCurrentRoom(Room* rptr) {currentRoom_ = rptr;
                                   currentRoom_->setVisited();}
  Room* getAddrByID(string ID) {return roomsID_[ID];}
  Room* getRoomByID(string ID) {return roomsID_[ID];}
  void printCurrent();
  void handleInput();

private:
  bool isDirection(string &direction);
  bool isHelp(string str);
  void printHelp();
  void shutDown();
  void moveRoom(string dir);
  void errorQuit(string messsage);
  map<string, Room*> roomsID_;
  map<string, Thing*> thingsID_;
  vector<Room*> rooms_;
  Room* currentRoom_;
  vector<Thing*> things_;
  vector<Thing*> inventory_;

};

#endif
