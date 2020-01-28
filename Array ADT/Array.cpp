#include "Array.h"

// Swap function
void swap(int& a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Constructor
Array::Array(const int& size, const int& length) 
:size(size), length(length) {
  // Dynamic allocate the memeory
  this->A = new int[this->size];
}

// Destructors
Array::~Array() {
  delete[] A;
  std::cout << "Destructor had been called" << std::endl;
}

// Getter for the size
int Array::getSize() const {
  return this->size;
}

// Setter for the size
void Array::setSize(int size) {
  this->size = size;
}

// Getter for the length
int Array::getLength() const {
  return this->length;
}
     
// Setter for the length
void Array::setLength(int length) {
  this->length = length;
}

// Append the array
void Array::append(const int& element) {
  // Check the index size
  if (this->length >= this->size) {
    std::cout << "Out of Index" << std::endl;
    return;
  }

  this->A[this->length] = element;
  (this->length)++;
}

// Insert the element
void Array::insert(const int& index, const int& element) {
  // Check the index size
  if (index >= this->size || this->length > this->size ||
      index < 0) {
    std::cout << "Out of index" << std::endl;
    return;
  }

  for (int i = this->length; i >= index; i--) {
    this->A[i] = (i == index)? element : A[i - 1];
  }

  (this->length)++;
}

// Delete the element by the index
void Array::del(const int& index) {
  // Check the index
  if (index < 0 || index >= this->length) {
    std::cout << "Out of index" << std::endl;
    return;
  }

  for (int i = index; i < this->length - 1; ++i) {
    this->A[i] = this->A[i + 1];
  }

  (this->length)--;
  std::cout << "\nAfter the deletion, the array is" << std::endl;
  std::cout << *this;
} 

int Array::linearSearch(const int& element) {
  for (int i = 0; i < this->length; ++i) {
    /* Common linear Search
    if (this->A[i] == element) {
      return i;
    } */

    /* Transposition
    if (this->A[i] == element) {
      swap(A[i], A[i - 1]);
      return i - 1;
    } */

    // Move to head
    if (this->A[i] == element) {
      swap(A[i], A[0]);
      return 0;
    }
  }

  return -1;
}

// Using Bineary Search to decrease the time complexity
int Array::binarySearch(const int& element) {
  // Using loop
  int l = 0;
  int h = this->length;
  int mid;

  while(l <= h) {
    mid = l + (h - l) / 2;

    if (this->A[mid] == element) {
      return mid;
    }
    else if (this->A[mid] < element) {
      l = mid + 1;
    }
    else {
      h = mid - 1;
    }
  }

  return -1;
}

// Using recursion to make Binary Search
int Array::recursionBinarySearch(int l, int h, int element) {
  if (l <= h) {
    int mid = l + (h - l) / 2;
    if (this->A[mid] == element) {
      return mid;
    }
    else if (this->A[mid] < element) {
      return recursionBinarySearch(mid + 1, h, element);
    }
    else {
      return recursionBinarySearch(l, mid - 1, element);
    }
  }

  return -1;
}

// Getter for the element in array
int Array::getElement(int index) {
  if (index >= 0 && index < this->length) {
    return this->A[index];
  }

  std::cout << "Out of index" << std::endl;
  return -1;
}

// Setter for the element in array
void Array::setElement(int index, int element) {
  if (index >= 0 && index < this->length) {
    this->A[index] = element;
    return;
  }

  std::cout << "Out of index" << std::endl;
}

// Find max element in array
int Array::findMax()  {
  int max = this->A[0];

  for (int i = 1; i < this->length; ++i) {
    max = (max < this->A[i])? this->A[i] : max;
  }

  return max;
}

// Find min element in array
int Array::findMin() {
  int min = this->A[0];

  for (int i = 1; i < this->length; ++i) {
    min = (min > this->A[i])? this->A[i] : min;
  }

  return min;
}

// Get the sum of the array
int Array::getSum() {
  int total = 0;

  for (int i = 0; i < this->length; ++i) {
    total += this->A[i];
  }

  return total;
}

// Get the average of the array
double Array::getAvg() {
  double total = (double)getSum();

  return total / this->length;
}

// Reverse the array
void Array::reverse() {
  for (int i = this->length - 1, j = 0; j < i; ++j, --i) {
    swap(this->A[i], this->A[j]);
  }
}

// Insert into already sorted array
void Array::insertSort(int element) {
  if (this->length == this->size) {
    std::cout << "Out of index" << std::endl;
    return;
  }

  int i;
  for (i = this->length - 1; this->A[i] > element; --i) {
    this->A[i + 1] = this->A[i];
  }

  this->A[i + 1] = element;

  (this->length)++;
}

// Check whether the array is sorted
int Array::isSorted() {
  for (int i = 0; i < this->length - 1; ++i) {
    if (this->A[i] > this->A[i + 1]) {
      return 0;
    }
  }
  
  return 1;
}

// Seperate the positve and negative number to each side
void Array::rearrange() {
  int i = 0, j = this->length - 1;

  while(i < j) {
    while (this->A[i] < 0) {
      ++i;
    }

    while (this->A[j] > 0) {
      --j;
    }

    if (i < j) {
      swap(this->A[i], this->A[j]);
    }
  }
}

// Overloading for the ostream
std::istream& operator >>(std::istream& input, const Array &array) {
  for (int i = 0; i < array.length; ++i) {
    input >> array.A[i];
  }

  return input;
}

// Overloading for the istream
std::ostream& operator <<(std::ostream& output, const Array &array) {
  for (int i = 0; i < array.length; ++i) {
    output << array.A[i] << " ";
  }
  output << std::endl;

  return output;
}


Array* mergingSort(const Array& tar1, const Array& tar2) {
  Array* result = new Array(tar1.length + tar2.length, tar1.size + tar2.size);
  
  int i = 0, j = 0, k = 0;

  while (i < tar1.length && j < tar2.length) {
    if (tar1.A[i] < tar2.A[j]) {
      result->A[k++] = tar1.A[i++];
    } else {
      result->A[k++] = tar2.A[j++];
    }
  }

  for (; i < tar1.length; ++i) {
    result->A[k++] = tar1.A[i];
  }

  for (; j < tar2.length; ++j) {
    result->A[k++] = tar2.A[j];
  }

  return result;
}

Array* Union(const Array& tar1, const Array& tar2) {
  Array* result = new Array(tar1.length + tar2.length, tar1.size + tar2.size);
  
  int i = 0, j = 0, k = 0;

  // After sorting the array
  // compare two array and find small one and append
  // increase the small one index and back to second step
  // until one of the array finish, append the rest of the element of the other array
  while (i < tar1.length && j < tar2.length) {
    if (tar1.A[i] < tar2.A[j]) {
      result->A[k++] = tar1.A[i++];
    } 
    else if (tar2.A[j] < tar1.A[i]) {
      result->A[k++] = tar2.A[j++];
    }
    else {
      result->A[k++] = tar1.A[i++];
      j++;
    }
  }

  for (; i < tar1.length; ++i) {
    result->A[k++] = tar1.A[i];
  }

  for (; j < tar2.length; ++j) {
    result->A[k++] = tar2.A[j];
  }

  result->length = k;
  return result;
}

Array* Intersect(const Array& tar1, const Array& tar2) {
  Array* result = new Array(tar1.length + tar2.length, tar1.size + tar2.size);
  
  int i = 0, j = 0, k = 0;

  // After sorting the array
  // compare two array and increase the index of smaller one
  // when find the same one increase both index
  // until one of the array finish, append the rest of the element of the other array
  while (i < tar1.length && j < tar2.length) {
    if (tar1.A[i] < tar2.A[j]) {
      i++;
    } 
    else if (tar2.A[j] < tar1.A[i]) {
      j++;
    }
    else {
      result->A[k++] = tar1.A[i++];
      j++;
    }
  }

  result->length = k;
  return result;
}

Array* Diff(const Array& tar, const Array& compare) {
  Array* result = new Array(tar.length + compare.length, tar.size + compare.size);
  
  int i = 0, j = 0, k = 0;

  // After sorting the array
  // compare two array and find small one
  // If it from tar, append and increase index. Else, do nothing and increase the index
  // Until one of the array finish, Using a for loop to ensure the tar element are all include or check
  while (i < tar.length && j < compare.length) {
    if (tar.A[i] < compare.A[j]) {
      result->A[k++] = tar.A[i++];
    } 
    else if (compare.A[j] < tar.A[i]) {
      j++;
    }
    else {
      i++;
      j++;
    }
  }

  for (; i < tar.length; ++i) {
    result->A[k++] = tar.A[i];
  }

  result->length = k;
  return result;
}