#include <iostream>
#include <vector>

#include "libraries/CLI11.hpp"

#include "../data/Descriptions.hpp"
#include "classes/Profile.h"
#include "classes/ProfilesManager.h"

using std::cout, std::endl, std::vector;

void writeAllProfiles(vector<Profile> profiles)
{
  if (profiles.size() == 0)
  {
    cout << "You have no profiles created yet.";
    return;
  }
  for (int i = 0; i < profiles.size(); i++)
    cout << i + 1 << ". " << profiles[i].getName() << endl;
}

int main(int argc, char const *argv[])
{
  Descriptions descriptions;
  ProfilesManager profilesManager;
  CLI::App app(descriptions.AppDescription);
  app.set_help_flag("--help", "Show list of basic flags and options.");
  app.set_help_all_flag("--help-all", "Show list of all flags and options.");

  app.add_flag_function(
      "-l, --list", [&](int count)
      { writeAllProfiles(profilesManager.getProfiles()); },
      "Return list of created profiles");

  string newProfileName = "";
  app.add_option("-a, --add", newProfileName, "Add new Profile");

  int deleteProfileIndex = -1;
  app.add_option("--delete-id", deleteProfileIndex, "Delete profile by id.");

  CLI11_PARSE(app, argc, argv);

  if (!newProfileName.empty())
    profilesManager.addProfile(newProfileName);

  if (deleteProfileIndex != -1)
    profilesManager.deleteProfile(deleteProfileIndex);

  return 0;
}