#pragma once

#include <iostream>
#include <fstream>
#include "../libraries/json.hpp"

using std::string, std::ifstream, std::ofstream;
using json = nlohmann::json;

class LocalStorage
{
private:
  json j;
  const string filepath = "../../../data/data.json";
public:
  LocalStorage();
  auto readData(string key);
  void saveData(string key, auto data);
};