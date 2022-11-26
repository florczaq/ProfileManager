#include "../Profile.h"

Profile::Profile(string name)
{
  this->name = name;
  paths.push_back("path1");
  paths.push_back("path2");
}

Profile::Profile(string name, vector<string> paths)
{
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

void Profile::addFile(string newFilePath)
{
  this->paths.push_back(newFilePath);
}

void Profile::writePaths()
{
  cout << "Pahs: \n";
  // for (string p : paths)
  //   cout << p << endl;
}