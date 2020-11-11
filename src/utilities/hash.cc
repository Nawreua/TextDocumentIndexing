#include "hash.hh"

namespace utilities {
template <> int hash<const char *>(const char *const &element) {
  int res = 0;
  for (int i = 0; element[i]; ++i)
    res = res * 53 + element[i];
  return res;
}
} // namespace utilities
