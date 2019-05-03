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

bool Room::removeThing(Thing* tptr)
{
  auto pos = find(things_.begin(), things_.end(), tptr);
  if (pos == things_.end())
  {
    cout << ("can't remove " + tptr->getID()) << endl;
    return false;
  }
  things_.erase(pos);
  return true;
}

void Room::look()
{

  // print exits_
  cout << "You see the exits:" << endl;
  for (auto exit : exits_) 
  {
    cout <<"- " << exit.first << endl;
  }
  cout << endl;
  //print things_
  cout << "You see:" << endl;
  for (auto tptr : things_) 
        cout << "- " << tptr->getID() << ' '
             << tptr->getDesc() << endl;
  cout << endl;
}
