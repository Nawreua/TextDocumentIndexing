#pragma once

#include <stdexcept>

namespace utilities {

template <typename Key, typename T, typename Hash, typename Eq>
map<Key, T, Hash, Eq>::map()
    : bucket_count_(DEFAULT_BUCKET_COUNT),
      buckets_(list<bucket>(bucket_count_)), hash_function_(Hash()),
      eq_function_(Eq()) {}

template <typename Key, typename T, typename Hash, typename Eq>
bool map<Key, T, Hash, Eq>::insert(const Key &key, const T &element) {
  int hash = hash_function_(key);
  bucket &b = buckets_[hash % bucket_count_];
  ssize_t index = b.keys_.index(key, eq_function_);
  if (index == -1) {
    b.keys_.add(key);
    b.elements_.add(element);
    return true;
  }
  return false;
}

template <typename Key, typename T, typename Hash, typename Eq>
T &map<Key, T, Hash, Eq>::operator[](const Key &key) const {
  int hash = hash_function_(key);
  bucket &b = buckets_[hash % bucket_count_];
  ssize_t index = b.keys_.index(key, eq_function_);
  if (index == -1)
    throw std::invalid_argument("Key not in map");
  return b.elements_[index];
}
template <typename Key, typename T, typename Hash, typename Eq>
bool map<Key, T, Hash, Eq>::contains(const Key &key) const {
  int hash = hash_function_(key);
  bucket &b = buckets_[hash % bucket_count_];
  ssize_t index = b.keys_.index(key, eq_function_);
  return index != -1;
}
} // namespace utilities
