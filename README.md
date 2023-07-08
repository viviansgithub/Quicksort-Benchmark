Quicksort Benchmark
This is one of the assignments I completed for my UTS Data Structures & Algorithms subject. In this exploration of quicksort: I investigated different ways to improve the performance of the basic version of quicksort discussed in one of my lectures. I included a Stopwatch class so I could time the algorithms on different inputs to report on what I see as shown in a Fibonacci tutorial.

Here are the three variations attempted:
1. Typically the base case of quicksort is when the size of the vector to be sorted is at most one.  In this case the vector is already sorted.  On a vector of size n, the base case will be reached n times.  All these function calls on small vectors can be time consuming.  I wrote a function with the signature

void insertionSortBaseCase(vecIter begin, vecIter end); 

that does the base case differently.  When begin and end define a range that is smaller than some threshold, then sort this range using insertion sort.  It is typically suggested that this change sees the most improvement when the threshold for switching to insertion sort is on vectors of size 8-16.  I played around with different thresholds to see if I could notice improvements over the basic version of quicksort. 

2.  What is the running time of the basic version of quicksort provided on a vector that is already sorted? We will now make a change to improve the running time of quicksort on a vector that is already sorted by implementing "median of 3" pivot selection.  In one of my lectures, the first element was always used in the range as the pivot element.  In median of 3 pivot selection we look at the first, middle, and last entries of the vector in the current range and use the element in between the maximum and minimum values of these three as the pivot.  The median of 3 pivot selection was added to my insertionSortBaseCase function in the function

void median3InsertionSortBaseCase(vecIter begin, vecIter end);
What is the running time of this quicksort with median of 3 pivot selection on a vector that is already sorted?

3. The third variation was left up to me with suggestions of trying something to see if I could make quicksort faster.  There was also a suggestion to consider another means of choosing the pivot, perhaps taking the pivot to be a random element in the vector.  Or you may look at a different partition algorithm, for example the Hoare Partition algorithm or Dijkstra's Partition algorithm.  For ease of our testing, please give your third variation this function name:

void thirdVariation(vecIter begin, vecIter end);

4 Files are included:
My code was implemented in the quicksort.cpp file.  The main.cpp was provided with test cases and some sample examples of how to measure the running times of a sorting variation on different inputs.  Finally the Stopwatch class was included in stopwatch.hpp for me to measure the performance of my algorithms.
