#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

#include "../libraries/CLI11.hpp"
#include "../../data/Descriptions.hpp"

#include "Profile.h"
#include "LocalStorage.h"

using std::cout, std::endl, std::vector, std::cin;

class ProfilesManager : public LocalStorage
{
private:
  vector<Profile> profiles;

  void renameProfile(int index);

public:
  ProfilesManager();

  void writeAllProfiles();
  void addProfile(string name);
  void deleteProfile(int index);
  void deleteProfile(string name);
  void editProfile(string name);
  void editProfile(int index);

  vector<Profile> getProfiles();

  int findProfile(string name);

  void addPathToProfile(int profileIndex, string newPath);
  void writePaths(int index);
};