#include "../Profile.h"
#include "Profile.h"

Profile::Profile(string name)
{
  this->name = name;
}

Profile::Profile(string name, vector<string> paths)
{
  this->name = name;
  this->paths = paths;
}

string Profile::getName()
{
  return name;
}

vector<string> Profile::getPaths()
{
  return paths;
}

void Profile::rename(string newName)
{
  this->name = newName;
}

void Profile::run()
{
  system("cls");
  for (auto path : paths)
  {
    if (path.find("http") != string::npos)
    {
      system(("start " + path).c_str());
    }
    else if (path[0] == '$')
    {
      string command = "";
      for (int i = 1; i < path.length(); i++)
        command += path[i];
      system(command.c_str());
    }
    else if (path.find(":/") != string::npos || path.find(":\\") != string::npos)
    {
      ShellExecuteA(GetDesktopWindow(), ("open"), LPCSTR(path.c_str()), NULL, NULL, SW_SHOWNORMAL);
    }
    else
    {
      cout << "Wrong syntax: \t" << path << endl;
    }
  }
}

void Profile::addPaths(vector<string> newPaths)
{
  for (auto path : newPaths)
    this->paths.push_back(path);
}

void Profile::writePaths()
{
  cout << "Paths: \n";
  for (int i = 0; i < paths.size(); i++)
  {
    cout << "  " << i + 1 << ": " << paths[i] << endl;
  }
}

void Profile::deletePats(vector<bool> selectedPaths)
{
  for (int i = 0; i < paths.size(); i++)
    if (selectedPaths[i])
      paths[i] = "";
  paths.erase(std::remove(paths.begin(), paths.end(), ""), paths.end());
}
