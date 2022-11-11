#include <iostream>
#include <vector>

#include "libraries/CLI11.hpp"

#include "../data/Descriptions.hpp"
#include "classes/Profile.h"
#include "classes/ProfilesManager.h"

using std::cout, std::endl, std::vector;

void writeAllProfiles(vector<Profile> profiles)
{
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

  auto profiles = app.add_subcommand("profiles", descriptions.ProfilesSubcommand);

  auto callback = [&](int count)
  { writeAllProfiles(profilesManager.getProfiles()); };
  profiles->add_flag_function("-l, --list", callback, "Return list of created profiles");


  CLI11_PARSE(app, argc, argv);
  return 0;
}