#ifndef _THING_H_
#define _THING_H_

#include <string>

using namespace std;

class Thing
{
  public:
    Thing (string id, string desc="") {id_=id; desc_=desc;held_=false;}
    string getID() {return id_;}
    
    string getDesc() {return desc_;}
    void setDesc(string desc) {desc_=desc;}   

    void setHeld() {held_=true;}
    bool held() {return held_;}

  private:
    string id_;
    string desc_;
    bool held_;
};

#endif