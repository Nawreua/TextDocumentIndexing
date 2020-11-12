#pragma once

#define DEFAULT_SIZE 5

#include <sys/types.h>

namespace utilities {

// Basic list implementation
//
// The implementation used memcpy previously to handle quickly modifications
// to the inner data list. However, it proved to be in conflict when dealing
// with list of list and as such, I switched to a simpler version
template <typename T> class list {
public:
  list();
  list(size_t count, const T &value = T());
  virtual ~list();

  list(const list &other);
  list(list &&other);

  list &operator=(const list &other);
  list &operator=(list &&other);

  // Element manipulation
  void add(const T &element);
  template <typename Cmp> void remove(const T &element, const Cmp &comparator);
  void replace(const T &element, size_t n);

  // Getter
  size_t size() const;
  size_t max_size() const;

  // Access the element at the nth position
  T &operator[](size_t n) const;

  // Find the first matching element
  template <typename Cmp>
  T *find(const T &element, const Cmp &comparator) const;

  // Get the index of the first matching element
  template <typename Cmp>
  ssize_t index(const T &element, const Cmp &comparator) const;

private:
  // The list in itself
  size_t size_;
  size_t max_size_;
  T *data_;
};
} // namespace utilities

#include "list.hxx"
