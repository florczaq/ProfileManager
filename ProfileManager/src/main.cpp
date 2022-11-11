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
    cout << i+1 << ". " << profiles[i].getName() << endl;
}

int main(int argc, char const *argv[])
{
  Descriptions descriptions;
  ProfilesManager profilesManager;

  CLI::App app(descriptions.AppDescription);
  app.set_help_flag("--help");

  auto profiles = app.add_subcommand("profiles", descriptions.ProfilesSubcommand);
  profiles->callback([&](){ writeAllProfiles(profilesManager.getProfiles()); });

  CLI11_PARSE(app, argc, argv);
  return 0;
}