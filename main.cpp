/*
 * CHAPTER 15, PROJECT 1
 * CS 151
 * Tu 5:30-9:20 with Porto
 * Programmer: Jay Montoya
 *
 *
 * PROBLEM STATEMENT:
 *      Design a class AbstractSort that can be used to analyze the number of comparisons
 *      performed by a sorting algorithm. The class should have a member function compare()
 *      that is capable of comparing two array elements, and a means of keeping track of the
 *      number of comparisons performed. The class should be an abstract class with a pure
 *      virtual member function:
 *
 *      void sort(int arr[] int size)
 *
 *      which, when overridden, will sort the array by calling the compare function to
 *      determine the relative order of pairs of numbers. Create a subclass of AbstractSort
 *      that uses a simple sorting algorithm to implement the sort function. The class should
 *      have a member function that can be called after the sorting is done to retrive the
 *      number of comparisons performed.
 *
 *
 */

#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}