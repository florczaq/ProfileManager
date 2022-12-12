#include "../ProfilesManager.h"

namespace ARROW
{
  const int UP = 72;
  const int DOWN = 80;
}

void move(char z, int &option, int vectorSize)
{
  switch (z)
  {
  case ARROW::UP:
    if (option > 0)
      option--;
    break;
  case ARROW::DOWN:
    if (option < vectorSize - 1)
      option++;
    break;
  }
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

// Add new paths to profile by index
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

// Writes list of paths to a profile specified by index
void ProfilesManager::writePaths(int index)
{
  profiles[index].writePaths();
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
  vector<string> menuOptions;

  menuOptions.push_back("+          Rename        +\n");
  menuOptions.push_back("+          Delete        +\n");
  menuOptions.push_back("+      Add more paths    +\n");
  menuOptions.push_back("+    Delete some paths   +\n");
  menuOptions.push_back("+    Show list of paths  +\n");
  menuOptions.push_back("+           Exit         +\n");

  while (int(z) != 13)
  {
    system("cls");

    cout << "Editing [" << name << "]: \n";
    cout << "+------------------------+\n";
    cout << "+         Options        +\n";
    cout << "+------------------------+\n";
    this->interactiveMenu(menuOptions, option);
    cout << "+------------------------+\n";

    z = _getch();
    move(z, option, menuOptions.size());
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
  case 4:
    writePaths(profileIndex);
    break;
  }
}

// Getting user menu choice
void ProfilesManager::interactiveMenu(vector<string> options, int option)
{
  for (int i = 0; i < options.size(); i++)
  {
    if (i == option)
      SetConsoleTextAttribute(handle, 128);
    cout << options.at(i);
    SetConsoleTextAttribute(handle, 15);
  }
}

// Adding new profile and getting name from user input
void ProfilesManager::addNewProfileMenu()
{
  string name;
  cout << "Name: ";
  cin >> name;
  addNewProfile(name);
}

// Profiles interactive list
void ProfilesManager::manageProfiles()
{
  int option = 0;
  char keyPressed;
  vector<string> nameList;
  string temp = "";
  string pName = "";
  int countSpaces = 0;

  for (int i = 0; i < profiles.size(); i++)
  {
    pName = profiles.at(i).getName();
    temp = "+";
    countSpaces = 12 - pName.length() / 2;

    for (int j = 0; j < countSpaces; j++)
      temp += ' ';
    temp += pName;
    for (int j = 0; j < 24 - countSpaces - pName.length(); j++)
      temp += ' ';
    temp += "+\n";

    nameList.push_back(temp);
  }
  nameList.push_back("+           +            +\n");

  while (keyPressed != 13)
  {
    system("cls");
    cout << "+------------------------+\n";
    cout << "+      Choose profile    +\n";
    cout << "+------------------------+\n";
    this->interactiveMenu(nameList, option);
    cout << "+------------------------+\n";
    keyPressed = getch();
    move(keyPressed, option, nameList.size());
  }
  system("cls");
  if (option == nameList.size() - 1)
  {
    addNewProfileMenu();
    exit(2);
  }
  else
    this->editProfile(profiles[option].getName());
}

// Main menu
void ProfilesManager::interactiveMainMenu()
{
  int option;
  char z;
  vector<string> menuOptions;
  menuOptions.push_back("+           Run          +\n");
  menuOptions.push_back("+      Manage profiles   +\n");
  menuOptions.push_back("+           List         +\n");
  menuOptions.push_back("+           Exit         +\n");

  while (true)
  {
    z = ' ';
    option = 0;

    while (z != 13)
    {
      system("cls");
      cout << "+------------------------+\n";
      cout << "+     Profile Manager    +\n";
      cout << "+------------------------+\n";
      interactiveMenu(menuOptions, option);
      cout << "+------------------------+\n";
      z = getch();
      move(z, option, menuOptions.size());
    }

    system("cls");

    switch (option)
    {
    case 0:
      break;
    case 1:
      this->manageProfiles();
      break;
    case 2:
      this->writeAllProfiles();
      getch();
      break;
    default:
      exit(1);
    }
  }
}
