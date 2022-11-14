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
private:
  const string filepath = "data/data.json";
  json j;
  json readData(string key);
  void saveData();

public:
  LocalStorage();

  vector<Profile> getProifilesList();

  void addNewProfile(string newProfileName);
  void deleteProfile(string name);
  void deleteProfile(int index);
};