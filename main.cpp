#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <cstdint>
#include "quicksort.hpp"
#include "stopwatch.hpp"

// checkSort sees if Quicksort::mySort 
// agrees with the outcome of std::sort
// you can let Quicksort::mySort call your 
// variations of quicksort to test them.
void checkSort(std::vector<int>& vec) {
  std::vector<int> copy {vec};
  std::sort(copy.begin(), copy.end());
  Quicksort::mySort(vec.begin(), vec.end());
  EXPECT_EQ(vec, copy);
}

TEST(quicksortTest, emptyTest) {
  std::vector<int> vec {};
  checkSort(vec);
}

TEST(quicksortTest, swap) {
  std::vector<int> vec {2, 1};
  checkSort(vec);
}

TEST(quicksortTest, reverseOrder) {
  std::vector<int> vec {3, 2, 1};
  checkSort(vec);
}

TEST(quicksortTest, maxAtFront) {
  std::vector<int> vec {1000, -4, 90, 98, -382, 67};
  checkSort(vec);
}

std::vector<int> generateRandomVector(std::size_t n, unsigned seed = 42) {
  std::mt19937 mt {seed};
  std::vector<int> vec(n);
  std::generate(vec.begin(), vec.end(), [&mt](){return mt();});
  return vec;
}

TEST(quicksortTest, randomTestSizeTen) {
  std::vector<int> vec = generateRandomVector(10, 2'342'343);
  checkSort(vec);
}

TEST(quicksortTest, randomTestSizeHundred) {
  std::vector<int> vec = generateRandomVector(100, 98'474'893);
  checkSort(vec);
}

TEST(quicksortTest, randomTestSizeThousand) {
  std::vector<int> vec = generateRandomVector(1000, 908'327);
  checkSort(vec);
}

TEST(quicksortTest, randomTestSizeTenThousand) {
  std::vector<int> vec = generateRandomVector(10'000, 2'343'849);
  checkSort(vec);
}

TEST(quicksortTest, randomTestSizeHundredThousand) {
  std::vector<int> vec = generateRandomVector(100'000, 458'927);
  checkSort(vec);
}

TEST(quicksortTest, randomTestSizeMillion) {
  std::vector<int> vec = generateRandomVector(1'000'000, 34'591'092);
  checkSort(vec);
}

void timeOnSortedVector(std::size_t n) {
  std::vector<int> vec(n);
  // create vector {0, 1, 2, ..., n-1}
  std::iota(vec.begin(), vec.end(), 0);
  std::vector<int> copy = vec;
  Stopwatch clock {};
  Quicksort::mySort(vec.begin(), vec.end());
  int64_t timeTaken = clock.elapsed<Stopwatch::microseconds>();
  std::cout << "mySort time on sorted vector of size " << n;
  std::cout  << " is " << timeTaken << " microseconds\n";
  clock.start();
  std::sort(copy.begin(), copy.end());
  timeTaken = clock.elapsed<Stopwatch::microseconds>();
  std::cout << "std::sort time on sorted vector of size " << n;
  std::cout  << " is " << timeTaken << " microseconds\n";
}

void timeOnRandomVector(std::size_t n, unsigned seed = 42) {
  std::vector<int> vec = generateRandomVector(n, seed);
  std::vector<int> copy = vec;
  Stopwatch clock {};
  Quicksort::mySort(vec.begin(), vec.end());
  int64_t timeTaken = clock.elapsed<Stopwatch::microseconds>();
  std::cout << "mySort time on random vector of size " << n;
  std::cout  << " is " << timeTaken << " microseconds\n";
  clock.start();
  std::sort(copy.begin(), copy.end());
  timeTaken = clock.elapsed<Stopwatch::microseconds>();
  std::cout << "std::sort time on random vector of size " << n;
  std::cout  << " is " << timeTaken << " microseconds\n";
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  const int n = 100'000;
  timeOnSortedVector(n);
  timeOnRandomVector(n);
  return RUN_ALL_TESTS();
}
