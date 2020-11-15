#pragma once

// The number of buckets by default in the map
#define DEFAULT_BUCKET_COUNT 100

#include "list.hh"

namespace utilities {
/**
 * Basic generic unordered map class
 *
 * Key represents the type of the key in the map
 * T represents the type of the value mapped to a key in the map
 * Hash represents a functor which computes a hash from a key: (Key) => int
 * Eq represents a functor for key equality: (Key, Key) => bool
 *
 * The map is implemented with a list of bucket, one for each possible hash,
 * modulo the number of allocated buckets. To solve the collision problem,
 * I chose to allow multiple keys to have the same index. This is an easy
 * solution and avoid spending time reallocating and displacing all the
 * buckets in case of bucket number modifications, at the cost of search time.
 * As such, we need to find a default number of buckets which reduce
 * collision while saving space.
 */
template <typename Key, typename T, typename Hash, typename Eq> class map {
public:
  /**
   * Default constructor
   *
   * @return An empty map
   */
  map();

  /**
   * Map an element for the given key, if the key is not already assigned
   *
   * @param key The key to the element
   * @param element The element mapped to the key
   * @return `true` if the insertion was successful, else `false`
   */
  bool insert(const Key &key, const T &element);

  /**
   * Get the element mapped to the key
   *
   * @param key The key to the element
   * @return The element mapped to the key
   * @throws std::invalid_argument If the key is not mapped
   */
  T &operator[](const Key &key) const;
  /**
   * Check if the key is mapped in the map
   *
   * @param key The key to check
   * @return `true` if the key is mapped, else `false`
   */
  bool contains(const Key &key) const;

private:
  /**
   * A bucket, containing a list of key and elements, mapped
   * 1 to 1 of each other. This solves the collision problem
   */
  struct bucket {
    list<Key> keys_;
    list<T> elements_;
  };

  // The number of allocated buckets
  size_t bucket_count_;
  /**
   * The internal list of buckets, one for each possible
   * hash modulo bucket_count_
   */
  list<bucket> buckets_;

  // The hash functor
  Hash hash_function_;
  // The equality functor
  Eq eq_function_;
};
} // namespace utilities

#include "map.hxx"
