#include "../ProfilesStorage.h"

vector<Profile> ProfilesStorage::getProfilesList()
{
  json result = LocalStorage::readData("Profiles");
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

void ProfilesStorage::addNewProfile(string name)
{
  LocalStorage::saveNewProfile(name);
}

void ProfilesStorage::deleteProfile(int index)
{
  LocalStorage::deleteProfile(index);
}
