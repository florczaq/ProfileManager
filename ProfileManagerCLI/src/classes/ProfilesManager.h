#pragma once

#include <vector>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>

#include "../libraries/CLI11.hpp"

#include "Profile.h"
#include "LocalStorage.h"

using std::cout, std::endl, std::vector, std::cin, std::getline;

class ProfilesManager : public LocalStorage
{
private:
  vector<Profile> profiles;

  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

  vector<Profile> getProfiles();

  void manageProfiles();
  void addNewProfileMenu();
  void renameProfile(int index);
  void deletePathsMenu(int profileIndex);
  void addPathsToProfile(int profileIndex);
  void interactiveMenu(vector<string> options, int currentOption);
  void selectionMenu(vector<string> options, vector<bool> selected, int currentOption);

  int interactiveProfilesList(bool withAddOption);

  bool confirmationMenu();

public:
  ProfilesManager();

  void writeAllProfiles();
  void interactiveMainMenu();
  void writePaths(int index);
  void runProfile(int index);
  void addProfile(string name);
  void editProfile(string name);
  void deleteProfile(int index);
  void deleteProfile(string name);

  int findProfile(string name);
};