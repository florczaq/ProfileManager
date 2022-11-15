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
  for (auto p : profiles)
    if (p.getName() == name)
    {
      std::cout << "You alredy have profile with that name. \nTry again with different name." << std::endl;
      return;
    }
  LocalStorage::addNewProfile(name);
}

void ProfilesManager::deleteProfile(int index)
{
  LocalStorage::deleteProfile(index);
}

void ProfilesManager::writeAllProfiles()
{
  if (profiles.size() == 0)
  {
    cout << "You have no profiles created yet.\n";
    return;
  }

  cout << "Profiles:   \n";
  for (int i = 0; i < profiles.size(); i++)
    cout << "  " << i + 1 << ". " << profiles[i].getName() << endl;
}

void ProfilesManager::deleteProfile(string name)
{
  string answear = "";
  cout << "Are you sure you want to delete this profile (y/n): " << name << endl;
  cout << ">> ";
  cin >> answear;
  if (answear[0] == 'y' || answear[0] == 'Y')
    LocalStorage::deleteProfile(name);
}