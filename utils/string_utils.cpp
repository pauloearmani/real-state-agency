
#include "./include/string_utils.hpp"
/*converte tudo para maiusculo*/
string toUpperCase(const string &str) {
  string result;
  for (char c : str) {
    result += toupper(c);
  }
  return result;
}