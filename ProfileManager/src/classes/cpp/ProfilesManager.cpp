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

void ProfilesManager::addPathToProfile(int profileIndex, string newPath)
{
  profiles[profileIndex].addFile(newPath);
}

// Search profiles list by name and returns index . If not found returns [-1]
int ProfilesManager::findProfile(string name)
{
  for (int i = 0; i < profiles.size(); i++)
    if (profiles[i].getName() == name)
      return i;
  return -1;
}

void ProfilesManager::writePaths(int index)
{
  cout << index << endl;
  // profiles[index].writePaths();
}

void ProfilesManager::editProfile(string name)
{
  int profileIndex = findProfile(name);
  if (profileIndex == -1)
  {
    cout << "You have no profiles with that name. \nCheck your profiles with [-l] flag";
    return;
  }

  int option = 0;
  cout << "Editing [" << name << "]: \n";
  cout << "\t+------------------------+\n";
  cout << "\t+         Options        +\n";
  cout << "\t+------------------------+\n";
  cout << "\t| 1) Rename              |\n";
  cout << "\t| 2) Delete              |\n";
  cout << "\t| 3) Add more paths      |\n";
  cout << "\t| 4) Delete some paths   |\n";
  cout << "\t| 5) Exit                |\n";
  cout << "\t+------------------------+\n";
  cout << "\n\t>> ";
  cin >> option;
  cout << "\n\n\n\n\n";

  switch (option)
  {
  case 1:
    cout << "Rename \n";
    break;
  case 2:
    cout << "Delete \n";
    break;
  case 3:
    cout << "Add more paths \n";
    break;
  case 4:
    cout << "Delete some paths \n";
    break;
  default:
    return;
  }
}