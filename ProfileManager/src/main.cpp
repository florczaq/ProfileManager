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
	string deleteProfileName = "";
	string editProfileName = "";
	string pathsListProfileName = "";
	int deleteProfileIndex = -1;

public:
	CLI::App app;

	Application()
	{
		app.description(descriptions.AppDescription);

		app.set_help_flag("--help", "Show list of basic flags and options.");
		app.set_help_all_flag("--help-all", "Show list of all flags and options.");

		app.add_option("-a, --add", newProfileName, "Add new Profile");
		app.add_option("-d,--delete", deleteProfileName, "Delete profile by name");
		app.add_option("-i,--delete-id", deleteProfileIndex, "Delete profile by id.");
		app.add_option("-e, --edit", editProfileName, "Open profile editor.");
		app.add_option("-t, --path-list", pathsListProfileName, "");

		app.add_flag_callback(
				"-m, --menu", [&]
				{ ProfilesManager::interactiveMainMenu(); },
				"Opens interactive menu.");

		app.add_flag_function(
				"-l, --list", [&](int i)
				{ ProfilesManager::writeAllProfiles(); },
				"Return list of created profiles");
	}

	void run()
	{
		if (!newProfileName.empty())
			ProfilesManager::addProfile(newProfileName);

		if (deleteProfileIndex != -1)
			ProfilesManager::deleteProfile(deleteProfileIndex - 1);

		if (!deleteProfileName.empty())
			ProfilesManager::deleteProfile(deleteProfileName);

		if (!editProfileName.empty())
			ProfilesManager::editProfile(editProfileName);

		if (!pathsListProfileName.empty())
			ProfilesManager::writePaths(ProfilesManager::findProfile(pathsListProfileName));
	}
};

int main(int argc, char const *argv[])
{
	Application application;
	CLI11_PARSE(application.app, argc, argv);
	application.run();
}