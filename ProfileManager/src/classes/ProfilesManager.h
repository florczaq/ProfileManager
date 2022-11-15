#pragma once

#include <iostream>
#include <vector>
#include "../libraries/CLI11.hpp"

#include "../../data/Descriptions.hpp"
#include "Profile.h"
#include "LocalStorage.h"

using std::cout, std::endl, std::vector, std::cin;

class ProfilesManager : public LocalStorage
{
private:
  vector<Profile> profiles;
public:
  ProfilesManager();

  void writeAllProfiles();
  void addProfile(string name);
  void deleteProfile(int index);
  void deleteProfile(string name);
  vector<Profile> getProfiles();
};

// https: // cliutils.github.io/CLI11/book/chapters/an-advanced-example.html