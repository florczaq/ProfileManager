#pragma once

#include <iostream>
#include <fstream>
#include "../libraries/json.hpp"

using std::string, std::ifstream, std::ofstream;
using json = nlohmann::json;

class LocalStorage
{
protected:
  json j;
  const string filepath = "data/data.json";
public:
  LocalStorage();
  json readData(string key);
  void saveData(string key, auto data);
};