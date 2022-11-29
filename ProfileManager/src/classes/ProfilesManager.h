#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <map>

#include "../libraries/CLI11.hpp"
#include "../../data/Descriptions.hpp"

#include "Profile.h"
#include "LocalStorage.h"

using std::cout, std::endl, std::vector, std::cin, std::map;

class ProfilesManager : public LocalStorage
{
private:
  vector<Profile> profiles;

  void renameProfile(int index);
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  void interactiveMenu(vector<string> options, int currentOption);
  void interactiveMenu(map<int,string> options, int currentOption);
  void manageProfiles();
public:
  ProfilesManager();

  void writeAllProfiles();
  void addProfile(string name);
  void deleteProfile(int index);
  void deleteProfile(string name);
  void editProfile(string name);
  void editProfile(int index);
  void interactiveMainMenu();

  vector<Profile> getProfiles();

  int findProfile(string name);

  void addPathsToProfile(int profileIndex);
  void writePaths(int index);
};