#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>

void swap(int& a, int& b);

class Array {
    private :
      int size, length;
      int *A;

    public :
      // Constructor
      Array(const int& size, const int& length);

      // Destructors
      ~Array();

      // Getter for the size
      int getSize() const;

      // Setter for the size
      void setSize(int size);

      // Getter for the length
      int getLength() const;
     
      // Setter for the length
      void setLength(int length);

      // Append the array
      void append(const int& element);

      // Insert the element
      void insert(const int& index, const int& element);

      // Delete the element from index
      void del(const int& index);

      // Search the element in the array
      // Two way to improve the linear search
      // First, Transposition
      // Second, Move to head
      int linearSearch(const int& element);

      // Using Bineary Search to decrease the time complexity
      int binarySearch(const int& element);

      // Using recursion to make Binary Search
      int recursionBinarySearch(int l, int h, int element);

      // Getter for the element in array
      int getElement(int index);

      // Setter for the element in array
      void setElement(int index, int element);

      // Find max element in array
      int findMax();

      // Find min element in array
      int findMin();

      // Get the sum of the array
      int getSum();

      // Get the average of the array
      double getAvg();

      // Reverse array
      void reverse();

      // Insert into already sorted array
      void insertSort(int element);

      // Check whether the array is sorted
      int isSorted();

      // Seperate the positve and negative number to each side
      void rearrange();

      // Istream overloading the array
      friend std::istream& operator >>(std::istream& input, const Array &array);

      // Ostream overloading the array
      friend std::ostream& operator <<(std::ostream& output, const Array &array);

      // Mergin two array with specific order to generate a new array
      friend Array* mergingSort(const Array& tar1, const Array& tar2);

      // Set operation for the union
      friend Array* Union(const Array& tar1, const Array& tar2);

      // Set operation for the intersection
      friend Array* Intersect(const Array& tar1, const Array& tar2);

      // Set operation for the difference
      friend Array* Diff(const Array& tar, const Array& compare);
};
#endif