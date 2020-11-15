#pragma once

#include "list.hh"
#include "map.hh"

#include <string>

namespace algorithm {
/**
 * A functor class for the string equality in the map
 */
class StringComparator {
public:
  /**
   * Check equality between two strings
   *
   * @param a The left string
   * @param b The right string
   * @return a == b
   */
  bool operator()(const std::string &a, const std::string &b) const;
};

/**
 * A functor class returning the hash of a string
 */
class HashFunction {
public:
  /**
   * Compute the hash of a given string
   *
   * @param str The string from which the hash is generated
   * @return The hash of the string
   */
  int operator()(const std::string &str) const;
};

/**
 * A map representing the index. Each word is a key to the files that contains
 * at least one reference to it.
 */
typedef utilities::map<std::string, utilities::list<std::string>, HashFunction,
                       StringComparator>
    index;

/**
 * Fill up an index using the directory path given by the user
 *
 * @param path The path to the directory containing the text files
 * @param index The index to fill
 */
void create_index(const std::string &path, index &index);

/**
 * Find if a word is references in the index
 *
 * @param word The word to check for references
 * @param index The index of word
 * @return The list of files containing the given word
 */
utilities::list<std::string> find_references(const std::string &word,
                                             const index &index);
} // namespace algorithm
