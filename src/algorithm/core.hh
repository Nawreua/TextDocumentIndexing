#pragma once

#include "list.hh"
#include "map.hh"

#include <string>

namespace algorithm {
class StringComparator {
public:
  bool operator()(const std::string &a, const std::string &b) const;
};

class HashFunction {
public:
  int operator()(const std::string &str) const;
};

typedef utilities::map<std::string, utilities::list<std::string>, HashFunction,
                       StringComparator>
    index;
void create_index(const std::string &path, index &index);
utilities::list<std::string> find_references(const std::string &word,
                                             const index &index);
} // namespace algorithm
