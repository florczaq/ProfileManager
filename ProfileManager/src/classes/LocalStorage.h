#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "../libraries/json.hpp"

#include "Profile.h"

using std::string,
    std::ifstream,
    std::ofstream,
    std::vector,
    std::to_string;

using json = nlohmann::json;

class LocalStorage
{
private:
  const string filepath = "data/data.json";
  json j;
  json readData(string key);
  void saveData();

protected:
  void addNewProfile(string newProfileName);
  void deleteProfile(int index);
  void saveChanges(vector<Profile> newProfilesList);

public:
  LocalStorage();

  vector<Profile> getProifilesList();
};