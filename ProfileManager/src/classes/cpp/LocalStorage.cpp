#include "../LocalStorage.h"

LocalStorage::LocalStorage()
{
  ifstream file(this->filepath);
  if (!file.good())
  {
    std::cout << "File: data.json not found at " << filepath << std::endl;
    file.close();
    ofstream file(this->filepath);
    j["Profiles"] = "[]";
    file << j;
    file.close();
    return;
  }
  j = json::parse(file);
  file.close();
}

json LocalStorage::readData(string key)
{
  return j[key];
}

void LocalStorage::saveData(string key, auto data)
{
  ofstream file(this->filepath);
  j[key] = data;
  file << j;
  file.close();
}