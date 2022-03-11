#include "Macro.hpp"

std::vector<std::string> SplitString(const std::string &_str, char _separator) {
  std::string s {_str};
  std::replace(s.begin(), s.end(), ',', ' ');
  std::stringstream ss {s};
  std::vector<std::string> vs;
  std::string temp;
  while (ss >> temp) { vs.push_back(temp); }
  return vs;
}