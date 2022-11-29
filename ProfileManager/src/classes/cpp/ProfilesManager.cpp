#include "../ProfilesManager.h"

namespace ARROW
{
  const int UP = 72;
  const int DOWN = 80;
}

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

void ProfilesManager::addPathsToProfile(int profileIndex)
{
  vector<string> paths;
  string input;
  int amount = 0;

  cout << "How many paths: ";
  cin >> amount;

  system("cls");

  cout << "New paths: \n";
  for (int i = 1; i <= amount; i++)
  {
    cout << " [" << i << "]: ";
    cin >> input;
    paths.push_back(input);
  }

  profiles[profileIndex].addPaths(paths);

  LocalStorage::saveChanges(profiles);
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

  char z;
  int option = 0;
  string menuOptions[5];
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  menuOptions[0] = "+          Rename        +\n";
  menuOptions[1] = "+          Delete        +\n";
  menuOptions[2] = "+      Add more paths    +\n";
  menuOptions[3] = "+    Delete some paths   +\n";
  menuOptions[4] = "+           Exit         +\n";

  while (int(z) != 13)
  {
    system("cls");

    cout << "Editing [" << name << "]: \n";
    cout << "+------------------------+\n";
    cout << "+         Options        +\n";
    cout << "+------------------------+\n";
    for (int i = 0; i < 5; i++)
    {
      if (i == option)
        SetConsoleTextAttribute(hConsole, 128);
      cout << menuOptions[i];
      SetConsoleTextAttribute(hConsole, 15);
    }
    cout << "+------------------------+\n";

    z = _getch();

    switch (z)
    {
    case ARROW::UP:
      if (option > 0)
        option--;
      break;
    case ARROW::DOWN:
      if (option < 4)
        option++;
      break;
    }
  }
  system("cls");
  switch (option)
  {
  case 0:
    renameProfile(profileIndex);
    break;
  case 1:
    deleteProfile(profileIndex);
    break;
  case 2:
    addPathsToProfile(profileIndex);
    break;
  case 3:
    cout << "Delete some paths \n";
    break;
  }
}