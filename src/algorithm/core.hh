#pragma once

#include "list.hh"
#include "map.hh"

#include <cstring>

namespace algorithm {
class StringComparator {
public:
  bool operator()(const char *const &a, const char *const &b);
};

class HashFunction {
public:
  int operator()(const char *const &string);
};

typedef utilities::map<const char *, utilities::list<const char *>,
                       HashFunction, StringComparator>
    index;
void create_index(char *path, index &index);
utilities::list<const char *> find_references(const char *word,
                                              const index &index);
} // namespace algorithm
