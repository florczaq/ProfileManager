#pragma once

#include <iostream>
#include <vector>
#include "../libraries/CLI11.hpp"

#include "../../data/Descriptions.hpp"
#include "Profile.h"
#include "LocalStorage.h"

using std::cout, std::endl, std::vector;

class ProfilesManager : public LocalStorage
{
private:
  vector<Profile> profiles;
public:
  ProfilesManager();

  void addProfile(string name);
  vector<Profile> getProfiles();
  void deleteProfile(int index);
};

// https: // cliutils.github.io/CLI11/book/chapters/an-advanced-example.html