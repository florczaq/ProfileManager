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

void Profile::addPath(string newFilePath)
{
  this->paths.push_back(newFilePath);
}

void Profile::rename(string newName)
{
  this->name = newName;
}

void Profile::addPaths(vector<string> newPaths)
{
  for (auto p : newPaths)
    this->paths.push_back(p);
}

void Profile::writePaths()
{
  cout << "Paths: \n";
  for (int i = 0; i < paths.size(); i++)
  {
    cout << "  " << i + 1 << ": " << paths[i] << endl;
  }
}