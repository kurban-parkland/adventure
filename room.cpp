#include <algorithm>
#include <vector>
#include "room.h"

using namespace std;

Room* Room::getExit(string dir)
{
  if ( exits_.find(dir) != exits_.end() )
    return exits_[dir];
  else
    return nullptr;
}

void Room::removeThing(Thing* tptr)
{
  auto pos = find(things_.begin(), things_.end(), tptr);
  if (pos == things_.end())
  {
    cout << ("can't remove " + tptr->getID()) << endl;
    exit(1);
  }
}
