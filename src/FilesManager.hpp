#include <iostream>
#include <vector>

#include "libraries/CLI11.hpp"

using std::vector, std::string;

enum RESULTS
{
  Success,
  Fail
};

class FileManager
{
private:
public:
  RESULTS addFileToProfile(CLI::App &app, vector<string> &profile, string newFilePath)
  {
    }
};