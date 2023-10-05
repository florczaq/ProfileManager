#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include "../libraries/CLI11.hpp"

using std::vector, std::string, std::cout, std::endl, std::wstring;

class Profile
{
private:
  string name = "";
  vector<string> paths;

public:
  Profile(string name);
  Profile(string name, vector<string> paths);

  string getName();
  vector<string> getPaths();

  void run();
  void writePaths();
  void rename(string newName);
  void addPaths(vector<string> newPaths);
  void deletePats(vector<bool> selectedPaths);
};