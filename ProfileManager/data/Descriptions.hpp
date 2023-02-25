#pragma once
#include <iostream>

using std::string;

namespace Descriptions
{
  const string AppDescription = "Profile Manager CLI is a command line interface.\n Each profile contains list of user's urls, CMD commands and .exe files paths that can be run.\n";
  const string AddPathsInfo = "########################################################################\n   Links must start with http or https [f.e. https:/www.example.com/]\n   Command lines must start with '$' [f.e. $echo Hello]\n   Programs paths must be absolute [f.e. C:/folder/example.exe]\n########################################################################\n\n";
};