#include <iostream>
#include <vector>
#include "src/libraries/CLI11.hpp"

#include "data/Descriptions.hpp"
#include "src/classes/Profile.hpp"

using std::cout, std::endl, std::vector;

enum OPTIONS
{
  ProfilesList
};

class ProfileManager
{
private:
  vector<Profile> profiles;

public:
  ProfileManager();
  vector<Profile> getProfiles();
};

ProfileManager::ProfileManager()
{
  profiles.push_back(Profile("Work"));
  profiles.push_back(Profile("Profile 2"));
  profiles.push_back(Profile("Game"));
  profiles.push_back(Profile("Profile 4"));
  profiles.push_back(Profile("Some Project"));
  profiles.push_back(Profile("Profile 6"));
}

vector<Profile> ProfileManager::getProfiles()
{
  return profiles;
}

void writeAllProfiles()
{
  ProfileManager pm;
  vector<Profile> vp = pm.getProfiles();
  for (Profile p : vp)
  {
    cout << p.getName() << endl;
  }
}

int main(int argc, char const *argv[])
{
  const Descriptions descriptions;
  const ProfileManager profileManager;

  CLI::App app(descriptions.AppDescription);
  app.set_help_flag("--help");
  
  auto profiles = app.add_subcommand("profiles", descriptions.ProfilesSubcommand);
  profiles->callback(&writeAllProfiles);

  CLI11_PARSE(app, argc, argv);
  return 0;
}
// https: // cliutils.github.io/CLI11/book/chapters/an-advanced-example.html
// app.add_option("-af, --add-file", file, "File name")->check(CLI::ExistingFile);