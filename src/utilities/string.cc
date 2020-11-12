#include "string.hh"

namespace utilities {
string::string() : size_(0), data_(new char[1]) { data_[0] = 0; }

string::string(const char *str)
    : size_(strlen(str)), data_(new char[size_ + 1]) {
  memcpy(data_, str, (size_ + 1) * sizeof(char));
}

string::~string() {
  delete[] data_;
  size_ = 0;
}

string::string(const string &other)
    : size_(other.size_), data_(new char[size_ + 1]) {
  memcpy(data_, other.data_, (size_ + 1) * sizeof(char));
}

string::string(string &&other) : size_(other.size_), data_(other.data_) {
  other.data_ = nullptr;
  other.size_ = 0;
}

string &string::operator=(const string &other) {
  if (this != &other) {
    delete[] data_;

    size_ = other.size_;
    data_ = new char[size_ + 1];

    memcpy(data_, other.data_, (size_ + 1) * sizeof(char));
  }
  return *this;
}

string &string::operator=(string &&other) {
  if (this != &other) {
    delete[] data_;

    size_ = other.size_;
    data_ = other.data_;

    other.size_ = 0;
    other.data_ = nullptr;
  }
  return *this;
}

size_t string::size() const { return size_; }

const char *string::c_str() const { return data_; }

char string::operator[](size_t n) const { return data_[n]; }

template <typename Cmp>
const char *string::find(char element, const Cmp &comparator) const {
  for (size_t i = 0; i < size_; ++i) {
    if (comparator(data_[i], element))
      return data_ + i;
  }
  return nullptr;
}

template <typename Cmp>
ssize_t string::index(char element, const Cmp &comparator) const {
  for (size_t i = 0; i < size_; ++i) {
    if (comparator(data_[i], element))
      return i;
  }
  return -1;
}
} // namespace utilities
