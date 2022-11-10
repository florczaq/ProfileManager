#include "../ProfilesManager.h"
 
ProfilesManager::ProfilesManager()
{
  profiles.push_back(Profile("Work"));
  profiles.push_back(Profile("Profile 2"));
  profiles.push_back(Profile("Game"));
  profiles.push_back(Profile("Profile 4"));
  profiles.push_back(Profile("Some Project"));
  profiles.push_back(Profile("Profile 6"));
}

vector<Profile> ProfilesManager::getProfiles()
{
  return profiles;
}