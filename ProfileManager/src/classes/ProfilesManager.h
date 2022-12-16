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

  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

  vector<Profile> getProfiles();

  void addNewProfileMenu();
  void addPathsToProfile(int profileIndex);
  void interactiveMenu(vector<string> options, int currentOption);
  void manageProfiles();
  void renameProfile(int index);
  void runProfile(int index);

  int interactiveProfilesList(bool withAddOption);

public:
  ProfilesManager();

  void addProfile(string name);
  void deleteProfile(int index);
  void deleteProfile(string name);
  void editProfile(string name);
  void interactiveMainMenu();
  void writeAllProfiles();
  void writePaths(int index);

  int findProfile(string name);
};