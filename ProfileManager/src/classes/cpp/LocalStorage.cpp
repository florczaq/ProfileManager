#include "../LocalStorage.h"

LocalStorage::LocalStorage()
{
  ifstream file(this->filepath);
  if (!file.good())
  {
    file.close();
    ofstream file(this->filepath);
    j["Profiles"] = "[]";
    file << j;
    file.close();
    return;
  }
  j = json::parse(file);
  file.close();
}


auto LocalStorage::readData(string key)
{
  return j[key];
}

void LocalStorage::saveData(string key, auto data)
{
  ofstream file(this->filepath);
  j[key] = data;
  file << j;
  file.close();
}

int main()
{
  LocalStorage localStorage;
  localStorage.saveData("test", "testToJest");
  std::cout << localStorage.readData("test") ;
}