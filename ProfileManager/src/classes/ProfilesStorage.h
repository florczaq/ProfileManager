#pragma once

#include <iostream>
#include <vector>

#include "../libraries/json.hpp"

#include "LocalStorage.h"
#include "Profile.h"

using std::vector;

class ProfilesStorage : public LocalStorage
{
private:
public:
  vector<Profile> getProfilesList();
};