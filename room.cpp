#include "room.h"

using namespace std;

Room* Room::getExit(string dir)
{
  if ( exits_.find(dir) != exits_.end() )
    return exits_[dir];
  else
    return nullptr;
}
