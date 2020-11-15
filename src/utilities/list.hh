#pragma once

#define DEFAULT_SIZE 5

#include <sys/types.h>

namespace utilities {

/** Basic generic list implementation
 *
 * The implementation used memcpy previously to handle quickly modifications
 * to the inner data list. However, it proved to be in conflict when dealing
 * with list of lists and as such, I switched to a simpler version
 */
template <typename T> class list {
public:
  /**
   * Default constructor
   *
   * @return An empty list with default max size
   */
  list();
  /**
   * Initialize a list from the parameters given
   *
   * @param count The number of values to insert
   * @param value The default value to copy
   * @return The initialized list
   */
  list(size_t count, const T &value = T());
  /**
   * Destructor, delete the inner allocated list
   */
  virtual ~list();

  /**
   * Copy constructor, allocate and copy elements
   *
   * @param other The list to copy
   * @return The copied list
   */
  list(const list &other);
  /**
   * Move constructor, steal the values
   *
   * @param other The list to move
   * @return The move list
   */
  list(list &&other);

  /**
   * Assign operator, delete the current values before copy
   *
   * @param other The list to copy
   * @return The copied list
   */
  list &operator=(const list &other);
  /**
   * Assign and move operator, delete the current values before move
   *
   * @param other The list to move
   * @return The moved list
   */
  list &operator=(list &&other);

  // Element manipulation
  /**
   * Add a given element to the list
   *
   * @param element The element to add
   */
  void add(const T &element);
  /**
   * Remove an element from the list
   *
   * @param element The element to remove
   * @param comparator The comparator functor which will check element equality
   * @throws std::logic_error When the element is not in the list
   */
  template <typename Cmp> void remove(const T &element, const Cmp &comparator);
  /**
   * Replace the element at the nth position
   *
   * @param element The new element
   * @param n The position of the element to replace
   * @throws std::out_of_range When n >= size
   */
  void replace(const T &element, size_t n);

  // Getter
  size_t size() const;
  size_t max_size() const;

  // Access the element at the nth position
  /**
   * Returns the element at the nth position
   *
   * @param n The position
   * @return The element
   */
  T &operator[](size_t n) const;

  // Find the first matching element
  /**
   * Attempts to find the element in the list
   *
   * @param element The element to find
   * @param comparator The comparator functor to check equality
   * @return A pointer to the element in the list, else nullptr if not present
   */
  template <typename Cmp>
  T *find(const T &element, const Cmp &comparator) const;

  // Get the index of the first matching element
  template <typename Cmp>
  /**
   * Attempts to find the position of the element in the list
   *
   * @param element The element to find
   * @param comparator The comparator functor to check equality
   * @return The index of the element in the list, else -1 if not present
   */
  ssize_t index(const T &element, const Cmp &comparator) const;

private:
  // The current size
  size_t size_;
  // The allocated size of the array
  size_t max_size_;
  // The allocated array containing the elements
  T *data_;
};
} // namespace utilities

#include "list.hxx"
