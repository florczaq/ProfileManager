#pragma once

#include <iostream>
#include <vector>
#include <windows.h>
#include <shellapi.h>
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

  string getName();
  vector<string> getFilesList();

  // void changeName(string newName);
  void addPath(string newFilePath);
  void addPaths(vector<string> newPaths);
  // void deleteFile(int index);
  void rename(string newName);
  void run();

  void writePaths();
};
