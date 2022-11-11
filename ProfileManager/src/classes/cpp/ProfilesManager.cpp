#include "../ProfilesManager.h"

ProfilesManager::ProfilesManager()
{
  ProfilesStorage profilesStorage;
  this->profiles = profilesStorage.getProfilesList();
}

vector<Profile> ProfilesManager::getProfiles()
{
  return profiles;
}