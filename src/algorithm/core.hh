#pragma once

#include "list.hh"
#include "map.hh"
#include "string.hh"

#include <cstring>

namespace algorithm {
class StringComparator {
public:
  bool operator()(const utilities::string &a, const utilities::string &b) const;
};

class HashFunction {
public:
  int operator()(const utilities::string &str) const;
};

typedef utilities::map<utilities::string, utilities::list<utilities::string>,
                       HashFunction, StringComparator>
    index;
void create_index(const utilities::string &path, index &index);
utilities::list<utilities::string>
find_references(const utilities::string &word, const index &index);
} // namespace algorithm
