#ifndef _ROOM_H_
#define _ROOM_H_
#include <map>
#include <vector>
#include <iostream>

#include "thing.h"

using namespace std;

class Room
{
public:
  Room(string id, string desc="") {id_=id;
                                   desc_=desc;
                                   visited_=false;}

  string getDesc() {return desc_;}
  void setDesc(string s) {desc_ = s;}

  void setVisited() {visited_ = true;}
  bool visited() {return visited_;}

  /// can't change the ID!
  string getID() {return id_;}

  void setExit(string dir, Room* to) {exits_[dir] = to;}
  Room* getExit(string dir);

  void addThing(Thing* tptr){things_.push_back(tptr);}
  bool removeThing(Thing *tptr);

  void look();

private:
  bool visited_;
  string desc_;
  string id_;
  map<string, Room*> exits_;  /// if it's not in the map, you can't go there
  vector<Thing*> things_;

};

#endif