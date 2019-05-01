#ifndef _THING_H_
#define _THING_H_

#include <string>

using namespace std;

class Thing
{
  public:
    Thing (string id, string desc="") {id_=id; desc_=desc;}
    string getID() {return id_;}
    
    string getDesc() {return desc_;}
    void setDesc(string desc) {desc_=desc;}    
  private:
    string id_;
    string desc_;
};

#endif