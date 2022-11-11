#include "../Profile.h"

Profile::Profile(string name)
{
  this->name = name;
}

Profile::Profile(string name, vector<string> paths){
  this->name = name;
  this->paths = paths;
}

string Profile::getName()
{
  return name;
}

vector<string> Profile::getFilesList()
{
  return paths;
}