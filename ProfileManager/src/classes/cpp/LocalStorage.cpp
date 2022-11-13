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

void LocalStorage::saveData()
{
  ofstream file(this->filepath);
  file << j;
  file.close();
}

void LocalStorage::saveNewProfile(string newProfileName)
{
  vector<json> profilesList;

  for (auto &p : j["Profiles"].items())
  {
    json element = p.value();
    profilesList.push_back(json::object({{"name", element.at("name")}, {"paths", element.at("paths")}}));
  }
  json object = json::object({{"name", newProfileName}, {"paths", json::array()}});

  profilesList.push_back(object);
  j["Profiles"] = profilesList;
  saveData();
}

void LocalStorage::deleteProfile(int index)
{
  vector<json> profilesList;
  int i = 0;
  for (auto &p : j["Profiles"].items())
  {
    if (i + 1 != index)
    {
      json element = p.value();
      profilesList.push_back(json::object({{"name", element.at("name")}, {"paths", element.at("paths")}}));
    }
    i++;
  }
  j["Profiles"] = profilesList;
  saveData();
}