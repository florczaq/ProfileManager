#pragma once

#include <iostream>
#include <vector>
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

  void changeName(string newName);
  void addFile(string newFilePath);
  void deleteFile(int index);
  void rename(string newName);

  void writePaths();
};
