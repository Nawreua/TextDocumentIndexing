#include "hash.hh"
#include "map.hh"

#include <cassert>

namespace tests {
class StringComparator {
public:
  bool operator()(const char *const &a, const char *const &b) const;
};
class HashFunction {
public:
  int operator()(const char *const &string) const;
};
bool StringComparator::operator()(const char *const &a,
                                  const char *const &b) const {
  return !strcmp(a, b);
}

int HashFunction::operator()(const char *const &string) const {
  return utilities::hash<const char *>(string);
}

using map = utilities::map<const char *, int, HashFunction, StringComparator>;

void map_initialization() {
  map m;
  assert(!m.contains("foo"));
  assert(!m.contains("bar"));
}

void map_manipulation() {
  map m;
  assert(m.insert("foo", utilities::hash<const char *>("foo")));
  assert(m.contains("foo"));
  assert(m.insert("bar", utilities::hash<const char *>("bar")));
  assert(m.contains("foo"));
  assert(m["foo"] == utilities::hash<const char *>("foo"));
  assert(m["bar"] == utilities::hash<const char *>("bar"));
  assert(!m.insert("foo", utilities::hash<const char *>("foo")));
}
} // namespace tests

int main() {
  tests::map_initialization();
  tests::map_manipulation();
  return 0;
}
