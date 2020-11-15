#pragma once

#include <cstring>
#include <stdexcept>

namespace utilities {
template <typename T>
list<T>::list() : size_(0), max_size_(DEFAULT_SIZE), data_(new T[max_size_]) {}

template <typename T>
list<T>::list(size_t count, const T &value)
    : size_(count), max_size_(count), data_(new T[max_size_]) {
  for (size_t i = 0; i < size_; i++)
    data_[i] = value;
}

template <typename T> list<T>::~list() {
  delete[] data_;
  size_ = 0;
  max_size_ = 0;
}

template <typename T>
list<T>::list(const list &other)
    : size_(other.size_), max_size_(other.max_size_), data_(new T[max_size_]) {
  for (size_t i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}

template <typename T>
list<T>::list(list &&other)
    : size_(other.size_), max_size_(other.max_size_), data_(other.data_) {
  other.data_ = nullptr;
  other.size_ = 0;
  other.max_size_ = 0;
}

template <typename T> list<T> &list<T>::operator=(const list &other) {
  if (this != &other) {
    delete[] data_;

    size_ = other.size_;
    max_size_ = other.max_size_;
    data_ = new T[max_size_];

    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }
  return *this;
}

template <typename T> list<T> &list<T>::operator=(list &&other) {
  if (this != &other) {
    delete[] data_;

    size_ = other.size_;
    max_size_ = other.max_size_;
    data_ = other.data_;

    other.size_ = 0;
    other.max_size_ = 0;
    other.data_ = nullptr;
  }
  return *this;
}

template <typename T> void list<T>::add(const T &element) {
  // If not enough space is available, we grow the inner array
  if (size_ >= max_size_) {
    max_size_ *= 2;
    T *tmp = new T[max_size_];
    T *old = data_;

    for (size_t i = 0; i < size_; ++i) {
      tmp[i] = old[i];
    }
    data_ = tmp;

    delete[] old;
  }
  data_[size_++] = element;
}

template <typename T>
template <typename Cmp>
void list<T>::remove(const T &element, const Cmp &comparator) {
  T *in_list = find(element, comparator);
  if (in_list == nullptr)
    throw std::logic_error("Non existing element");

  size_t pos = in_list - data_;
  if (pos != size_ - 1) {
    for (size_t i = 0; i < size_ - pos - 1; ++i) {
      in_list[i] = in_list[i + 1];
    }
    // memmove(in_list, in_list + 1, (size_ - pos - 1) * sizeof(T));
  }
  size_--;

  /**
   * We could also shrink the underlying array, based on an heuristic
   * of the size / max size, however we do not actually need to remove
   * elements in our case.
   */
}

template <typename T> void list<T>::replace(const T &element, size_t n) {
  if (n >= size_)
    throw std::out_of_range("Out of range");
  data_[n] = element;
}

template <typename T> size_t list<T>::size() const { return size_; }

template <typename T> size_t list<T>::max_size() const { return max_size_; }

template <typename T> T &list<T>::operator[](size_t n) const {
  return data_[n];
}

template <typename T>
template <typename Cmp>
T *list<T>::find(const T &element, const Cmp &comparator) const {
  for (size_t i = 0; i < size_; ++i) {
    if (comparator(data_[i], element))
      return data_ + i;
  }
  return nullptr;
}

template <typename T>
template <typename Cmp>
ssize_t list<T>::index(const T &element, const Cmp &comparator) const {
  for (size_t i = 0; i < size_; ++i) {
    if (comparator(data_[i], element))
      return i;
  }
  return -1;
}
} // namespace utilities
