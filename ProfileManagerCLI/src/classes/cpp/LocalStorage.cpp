#include "../LocalStorage.h"

LocalStorage::LocalStorage()
{
  ifstream file(this->filepath);
  if (!file.good())
  {
    std::cout << "File: data.json not found at " << filepath << std::endl;
    std::cout << "Rerun the application. \nIf problem repeats reinstall the application." << std::endl;
    file.close();

    ofstream file(this->filepath);
    j["Profiles"] = json::array();
    file << j;
    file.close();
    exit(1);
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

void LocalStorage::addNewProfile(string newProfileName)
{
  vector<json> profilesList;

  for (auto &profile : j["Profiles"].items())
  {
    json element = profile.value();
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
  for (auto &profile : j["Profiles"].items())
  {
    json element = profile.value();
    if (i != index)
      profilesList.push_back(json::object({{"name", element.at("name")}, {"paths", element.at("paths")}}));
    i++;
  }
  j["Profiles"] = profilesList;
  saveData();
}

void LocalStorage::saveChanges(vector<Profile> profiles)
{
  vector<json> newProfilesList;
  int i = 0;
  for (auto &p : j["Profiles"].items())
  {
    newProfilesList.push_back(json::object({{"name", profiles.at(i).getName()}, {"paths", profiles.at(i).getPaths()}}));
    i++;
  }
  j["Profiles"] = newProfilesList;
  saveData();
}

vector<Profile> LocalStorage::getProifilesList()
{
  json result = readData("Profiles");
  vector<Profile> profiles;
  for (auto &element : result.items())
  {
    json object = element.value();
    profiles.push_back(
        Profile(
            object.at("name").get<string>(),
            object.at("paths").get<vector<string>>()));
  }
  return profiles;
}