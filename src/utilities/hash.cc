#include "hash.hh"

namespace utilities {
// Simple string hash function
template <> int hash<const char *>(const char *const &element) {
  int res = 0;
  for (int i = 0; element[i]; ++i)
    res = res * 53 + element[i];
  return res;
}

// Int hash using the 32 bit mix function
template <> int hash<int>(const int &element) {
  int res = element;
  res = ~res + (res << 15); // res = (res << 15) - res - 1;
  res = res ^ (res >> 12);
  res = res + (res << 2);
  res = res ^ (res >> 4);
  res = res * 2057; // res = (res + (res << 3)) + (res << 11);
  res = res ^ (res >> 16);
  return res;
}
} // namespace utilities
