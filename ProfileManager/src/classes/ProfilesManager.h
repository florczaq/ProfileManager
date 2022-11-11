#pragma once

#include <iostream>
#include <vector>
#include "../libraries/CLI11.hpp"

#include "../../data/Descriptions.hpp"
#include "Profile.h"

using std::cout, std::endl, std::vector;

class ProfilesManager
{
private:
  vector<Profile> profiles;

public:
  ProfilesManager();
  vector<Profile> getProfiles();
};




// https: // cliutils.github.io/CLI11/book/chapters/an-advanced-example.html
// app.add_option("-af, --add-file", file, "File name")->check(CLI::ExistingFile);