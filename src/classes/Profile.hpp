#include <iostream>
#include <vector>

using std::vector, std::string;

class Profile
{
private:
  string name = "";
  vector<string> paths;

public:
  Profile(string name);

  string getName();
  vector<string> getFilesList();

  void changeName(string newName);
  void addFile(string newFilePath);
  void deleteFile(int index);
};

Profile::Profile(string name)
{
  this->name = name;
}

string Profile::getName()
{
  return name;
}

vector<string> Profile::getFilesList()
{
  return paths;
}