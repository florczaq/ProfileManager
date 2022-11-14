#include "../ProfilesManager.h"

ProfilesManager::ProfilesManager()
{
  this->profiles = LocalStorage::getProifilesList();
}

vector<Profile> ProfilesManager::getProfiles()
{
  return profiles;
}

void ProfilesManager::addProfile(string name)
{
  LocalStorage::saveNewProfile(name);
}

void ProfilesManager::deleteProfile(int index)
{
  LocalStorage::deleteProfile(index);
}