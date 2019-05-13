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

class AbstractSort {
private:
    int numComparisons;

public:
    AbstractSort() {
        numComparisons = 0;
    }


    // pure virtual function
    virtual void sort(int arr[], int size) = 0;

    // simple compare function that returns 0 if equal, -1 if x preceeds y, and +1 if y preceeds x
    int compare(int x, int y) {
        numComparisons++;
        if (x == y)
            return 0;
        else if (x < y)
            return -1;
        else
            return 1;
    }

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    // accessor function for the number of comparisons in this sort
    int getNumComparisons() { return numComparisons; }

};

class BubbleSort : public AbstractSort {
public:

    // performs a simbple bubblesort on the array given the array and it's size
    void sort(int arr[], int size) {

        // declare 2 indexes to iterate through
        int i, j;

        // boolean to track swaps in the sort
        bool swapped;
        for (i = 0; i < size-1; i++)
        {
            // set swap flag
            swapped = false;
            for (j = 0; j < size-i-1; j++)
            {

                if (compare(arr[j], arr[j+1]) > 0)
                {
                    // swap() function added to base class AbstractSort since it can be applied to multiple types of
                    // sorts
                    swap(&arr[j], &arr[j+1]);

                    // set swap flag
                    swapped = true;
                }
            }

            // if no two elements were swapped by inner loop, then break
            if (!swapped)
                break;
        }
    }

};

int main() {

    // greeting
    cout << "Welcome to the demo of project 1!";

    // create array
    cout << "\n\nCreating array...";
    int values[] = {12,35,65,34,86,45,33,12,42,3,54,24,66442,2,4312,3,312,12,3,12,312,3,1};
    int size = 23;

    // print array
    cout << "\n\n\tARRAY CREATED: ";
    for (int i = 0; i < size; i++) {
        cout << *(values + i) << " ";
    }

    // create sorting mechanism
    BubbleSort bs;

    // SORT
    cout << "\n\nSorting...";
    bs.sort(values, size);

    // print array
    cout << "\n\n\tARRAY SORTED: ";
    for (int i = 0; i < size; i++) {
        cout << *(values + i) << " ";
    }

    // print number of comparisons
    cout << "\n\tNumber of comparisons used: " << bs.getNumComparisons() << "\n\n";

    // end program
    return 0;
}