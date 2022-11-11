#include "../Profile.h"

Profile::Profile(string name)
{
  this->name = name;
}

string Profile::getName()
{
  return name;
}

vector<string> Profile::getFilesList()
{
  return paths;
}