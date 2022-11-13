#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "../libraries/json.hpp"

#include "Profile.h"

using std::string, std::ifstream, std::ofstream, std::vector, std::to_string;
using json = nlohmann::json;

class LocalStorage
{
protected:
  json j;
  const string filepath = "data/data.json";
public:
  LocalStorage();
  json readData(string key);
  void saveData();
  void saveNewProfile(string newProfileName);
  void deleteProfile(string name);
  void deleteProfile(int index);
};