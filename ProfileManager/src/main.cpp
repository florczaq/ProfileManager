#include <iostream>
#include <vector>

#include "libraries/CLI11.hpp"

#include "../data/Descriptions.hpp"
#include "classes/Profile.h"
#include "classes/ProfilesManager.h"

using std::cout, std::endl, std::vector;

class Application : public ProfilesManager
{
private:
  Descriptions descriptions;

  string newProfileName = "";
  int deleteProfileIndex = -1;
  string deleteProfileName = "";

public:
  CLI::App app;

  Application()
  {
    app.description(descriptions.AppDescription);
    app.set_help_flag("--help", "Show list of basic flags and options.");
    app.set_help_all_flag("--help-all", "Show list of all flags and options.");
    app.add_option("-a, --add", newProfileName, "Add new Profile");
    app.add_option("--di,--delete-id", deleteProfileIndex, "Delete profile by id.");
    app.add_flag_function(
        "-l, --list", [&](int i)
        { ProfilesManager::writeAllProfiles(); },
        "Return list of created profiles");
    app.add_option("-d,--delete", deleteProfileName, "Delete profile by name");
  }

  void run()
  {
    if (!newProfileName.empty())
      ProfilesManager::addNewProfile(newProfileName);

    if (deleteProfileIndex != -1)
      ProfilesManager::deleteProfile(deleteProfileIndex);

    if (!deleteProfileName.empty())
      ProfilesManager::deleteProfile(deleteProfileName);
  }
};

int main(int argc, char const *argv[])
{
  Application application;
  CLI11_PARSE(application.app, argc, argv);
  application.run();

  return 0;
}