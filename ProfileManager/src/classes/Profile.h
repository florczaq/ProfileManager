#pragma once

#include <iostream>
#include <vector>
#include <windows.h>
#include "../libraries/CLI11.hpp"

using std::vector, std::string, std::cout, std::endl;

class Profile
{
private:
  string name = "";
  vector<string> paths;
  
public:
  Profile(string name);
  Profile(string name, vector<string> paths);

  vector<string> getFilesList();

  string getName();

  void run();
  void rename(string newName);
  void addPaths(vector<string> newPaths);
  void writePaths();
};
