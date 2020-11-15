#pragma once

#include <cstring>
#include <sys/types.h>

namespace utilities {

/**
 * Basic immutable string implementation, in case std::string was not authorized
 * @deprecated
 */
class string {
public:
  string();
  string(const char *str);
  virtual ~string();

  string(const string &other);
  string(string &&other);

  string &operator=(const string &other);
  string &operator=(string &&other);

  // Getter
  size_t size() const;
  const char *c_str() const;

  // Access the element at the nth position
  char operator[](size_t n) const;

  // Find the first matching element
  template <typename Cmp>
  const char *find(char element, const Cmp &comparator) const;

  // Get the index of the first matching element
  template <typename Cmp>
  ssize_t index(char element, const Cmp &comparator) const;

  friend inline bool operator==(const string &a, const string &b) {
    return !strcmp(a.data_, b.data_);
  }
  friend inline bool operator!=(const string &a, const string &b) {
    return strcmp(a.data_, b.data_);
  }
  friend inline bool operator==(const string &a, const char *b) {
    return !strcmp(a.data_, b);
  }
  friend inline bool operator!=(const string &a, const char *b) {
    return strcmp(a.data_, b);
  }
  friend inline bool operator==(const char *a, const string &b) {
    return !strcmp(a, b.data_);
  }
  friend inline bool operator!=(const char *a, const string &b) {
    return strcmp(a, b.data_);
  }

private:
  // The string in itself
  size_t size_;
  char *data_;
};
} // namespace utilities
