#pragma once

#define DEFAULT_BUCKET_COUNT 100

#include "list.hh"

namespace utilities {
template <typename Key, typename T, typename Hash, typename Eq> class map {
public:
  map();

  bool insert(const Key &key, const T &element);

  T &operator[](const Key &key) const;
  bool contains(const Key &key) const;

private:
  struct bucket {
    list<Key> keys_;
    list<T> elements_;
  };
  size_t bucket_count_;
  list<bucket> buckets_;
  Hash hash_function_;
  Eq eq_function_;
};
} // namespace utilities

#include "map.hxx"
