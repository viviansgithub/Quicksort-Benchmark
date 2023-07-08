#include <iostream>
#include <vector>
#include <utility>
#include "quicksort.hpp"

using vecIter = Quicksort::vecIter;

vecIter lomutoPartition(vecIter begin, vecIter end) {
  vecIter leftEnd = begin + 1;
  for (vecIter j = begin + 1; j < end; ++j) {
    if (*j <= *begin) {
      std::swap(*leftEnd, *j);
      ++leftEnd;
    }
  }
  std::swap(*begin, *(leftEnd-1));
  return leftEnd - 1;
}

void Quicksort::basic(vecIter begin, vecIter end) {
  if (end - begin <= 10) {
    insertionSortBaseCase(begin, end);
    return;
  }
  vecIter pivotIt = lomutoPartition(begin, end);
  basic(begin, pivotIt);
  basic(pivotIt+1, end);
}

void Quicksort::insertionSortBaseCase(vecIter begin, vecIter end) {
  if (end - begin <=1){
    return;
  }
  for (vecIter i = begin + 1; i < end; ++i){
    auto key = *i;
    auto j = i - 1;
    while (j >= begin && *j > key){
      *(j+1) = *j;
      --j;
    }
    *(j + 1)= key;
  }
}

void Quicksort::median3InsertionSortBaseCase(vecIter begin, vecIter end) {
  if (end - begin <= 1) {
    return;
  }
  if (end - begin <=10){
    insertionSortBaseCase(begin, end);
    return;
  }
}

void Quicksort::thirdVariation(vecIter begin, vecIter end) {
}

void Quicksort::mySort(vecIter begin, vecIter end) {
  basic(begin, end);
}
