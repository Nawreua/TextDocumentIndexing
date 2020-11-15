#pragma once

namespace utilities {
/**
 * Templated hash function, specialized according to the type given
 *
 * @param element The element from which the hash will be computed
 * @return Hash representation of the element
 */
template <typename T> int hash(const T &element);
} // namespace utilities
