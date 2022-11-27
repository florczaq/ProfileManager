#include "../ProfilesManager.h"

ProfilesManager::ProfilesManager()
{
  this->profiles = LocalStorage::getProifilesList();
}

// Returns list of created profiles
vector<Profile> ProfilesManager::getProfiles()
{
  return profiles;
}

// Search profiles list by name and returns index . If not found returns [-1]
int ProfilesManager::findProfile(string name)
{
  for (int i = 0; i < profiles.size(); i++)
    if (profiles[i].getName() == name)
      return i;
  return -1;
}

// Renames profile
void ProfilesManager::renameProfile(int index)
{
  string newName = "";
  cout << "Enter new name: ";
  cin >> newName;
  profiles[index].rename(newName);
  LocalStorage::saveChanges(profiles);
}

// Add new  profile to the list
void ProfilesManager::addProfile(string name)
{
  if (findProfile(name) != -1)
  {
    std::cout << "You alredy have profile with that name. \nTry again with different name." << std::endl;
    return;
  }
  LocalStorage::addNewProfile(name);
}

// Delete profile by index
void ProfilesManager::deleteProfile(int index)
{
  string answear = "";
  cout << "Are you sure you want to delete this profile (y/n) \n>> ";
  cin >> answear;

  if (answear[0] == 'y' || answear[0] == 'Y')
    LocalStorage::deleteProfile(index);
}

// Deletes profile by name
void ProfilesManager::deleteProfile(string name)
{
  int index = this->findProfile(name);
  if (index == -1)
  {
    cout << "No profile was found with this name.\n";
    return;
  }
  this->deleteProfile(index);
}

// Write list of profiles
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

void ProfilesManager::addPathToProfile(int profileIndex, string newPath)
{
  profiles[profileIndex].addFile(newPath);
}

void ProfilesManager::writePaths(int index)
{
  cout << index << endl;
  // profiles[index].writePaths();
}

// Open edition menu 
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
  cout << "+------------------------+\n";
  cout << "+         Options        +\n";
  cout << "+------------------------+\n";
  cout << "| 1) Rename              |\n";
  cout << "| 2) Delete              |\n";
  cout << "| 3) Add more paths      |\n";
  cout << "| 4) Delete some paths   |\n";
  cout << "| 5) Exit                |\n";
  cout << "+------------------------+\n";
  cout << "\n>> ";
  cin >> option;
  cout << "\n\n";

  switch (option)
  {
  case 1:
    renameProfile(profileIndex);
    break;
  case 2:
    deleteProfile(profileIndex);
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