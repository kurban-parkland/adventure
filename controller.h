#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <vector>
#include <map>

#include "room.h"

using namespace std;

class Controller
{
 public:
  void addRoom(Room* rptr) {rooms_.push_back(rptr); 
    addrs_[rptr->getID()] = rptr;}
  void addExit(Room* from, Room* to, string dir) 
  {   from->setExit(dir, to); }
  void printAllRooms();
  void setCurrentRoom(Room* rptr) {currentRoom_ = rptr;}
  Room* getAddrByID(string ID) {return addrs_[ID];}
  void printCurrent();
  void handleInput();
  bool isDirection(string &direction);
 private:
  void moveRoom(string dir);
  map<string, Room*> addrs_;
  vector<Room*> rooms_;
  Room* currentRoom_;

};

#endif
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <vector>
#include <map>

#include "room.h"

using namespace std;

class Controller
{
 public:
  void addRoom(Room* rptr) {rooms_.push_back(rptr); 
    addrs_[rptr->getID()] = rptr;}
  void addExit(Room* from, Room* to, string dir) 
  {   from->setExit(dir, to); }
  void printAllRooms();
  void setCurrentRoom(Room* rptr) {currentRoom_ = rptr;}
  Room* getAddrByID(string ID) {return addrs_[ID];}
  void printCurrent();
  void handleInput();
  bool isDirection(string &direction);
 private:
  void moveRoom(string dir);
  map<string, Room*> addrs_;
  vector<Room*> rooms_;
  Room* currentRoom_;

};

#endif
