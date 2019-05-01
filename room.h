#ifndef _ROOM_H_
#define _ROOM_H_
#include <map>
#include <iostream>

using namespace std;

class Room
{
 public:
  Room(string id, string desc="") {id_=id;desc_=desc;}
  string getDesc() {return desc_;}
  string getID() {return id_;}
  void setExit(string dir, Room* to) {exits_[dir] = to;}
  Room* getExit(string dir);
 private:
  string desc_;
  string id_;
  map<string, Room*> exits_;  /// if it's not in the map, you can't go there

};

#endif
