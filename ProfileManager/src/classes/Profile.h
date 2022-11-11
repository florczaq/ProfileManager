#pragma once

#include <iostream>
#include <vector>

using std::vector, std::string;

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
};
