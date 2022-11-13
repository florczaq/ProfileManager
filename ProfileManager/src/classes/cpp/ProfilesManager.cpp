#include "../ProfilesManager.h"

ProfilesManager::ProfilesManager()
{
  this->profiles = profilesStorage.getProfilesList();
}

vector<Profile> ProfilesManager::getProfiles()
{
  return profiles;
}

void ProfilesManager::addProfile(string name){
  profilesStorage.addNewProfile(name);
}