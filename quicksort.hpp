#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <vector>

namespace Quicksort {

using vecIter = std::vector<int>::iterator;

void basic(vecIter begin, vecIter end);
void insertionSortBaseCase(vecIter begin, vecIter end);
void median3InsertionSortBaseCase(vecIter begin, vecIter end);
void thirdVariation(vecIter begin, vecIter end);
void mySort(vecIter begin, vecIter end);

}         // end namespace Quicksort

#endif    // QUICKSORT_HPP_


