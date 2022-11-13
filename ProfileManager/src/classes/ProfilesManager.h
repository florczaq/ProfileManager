#pragma once

#include <iostream>
#include <vector>
#include "../libraries/CLI11.hpp"

// #include "data/Descriptions.hpp"
#include "../../data/Descriptions.hpp"
#include "ProfilesStorage.h"
#include "Profile.h"

using std::cout, std::endl, std::vector;

class ProfilesManager
{
private:
  vector<Profile> profiles;
  ProfilesStorage profilesStorage;
public:
  ProfilesManager();

  void addProfile(string name);
  vector<Profile> getProfiles();
  void deleteProfile(int index);
};

// https: // cliutils.github.io/CLI11/book/chapters/an-advanced-example.html