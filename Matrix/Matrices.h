#ifndef MATRICES_H
#define MATRICES_H

#include<iostream>

template <class T>
class Diagonal_Matrix {
  private :
    T size;
    T *array;

  public :
    // Constructor
    // Using 1D array to save space
    Diagonal_Matrix(int size);

    // Destructor
    ~Diagonal_Matrix();

    // Create the matrix
    void create_matrix();

    // change the element of matrix
    void set_matrix();

    // Get the element of the matrix
    T get_element(int i, int j);

    // Display the matrix
    void display_matrix();
};

// Constructor for Diagonal Matrix
template <class T>
Diagonal_Matrix<T>::Diagonal_Matrix(int size)
: size(size) {
  array = new T[size];
}

// Destructor for Diagonal Matrix
template <class T>
Diagonal_Matrix<T>::~Diagonal_Matrix() {
  delete[] array;
}

// Create the matrix in Diagonal Matrix
template <class T>
void Diagonal_Matrix<T>::create_matrix() {
  std::cout << "Enter " << size << " numbers." << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
}

// Change the matrix in Diagonal Matrix
template <class T>
void Diagonal_Matrix<T>::set_matrix() {
  T element;
  int i, j;

  std::cout << "\nEnter element, row and column." << std::endl;
  std::cin >> element >> i >> j;
  
  if (i <= 0 || i > size || j <= 0 || j > size) {
    std::cout << "\nOut of index" << std::endl;
    std::cout << "Index should be 1 to " << size << std::endl;
    return;
  }

  if (i != j) {
    std::cout << "\nCan only change the diagonal element." << std::endl;
    return;
  }

  this->array[i - 1] = element;
}

// Get the element in Diagonal Matrix
template <class T>
T Diagonal_Matrix<T>::get_element(int i, int j) {
  if (i <= 0 || i > size || j <= 0 || j > size) {
    std::cout << "Out of index" << std::endl;
    std::cout << "Index should be 1 to " << size << std::endl;
    return -1;
  }

  if (i == j) {
    return this->array[i - 1];
  }

  return 0;
}

// Display the matrix in Diagonal Matrix
template <class T>
void Diagonal_Matrix<T>::display_matrix() {
  std::cout << "\n";

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      (i != j)? (std::cout << "0 ") : (std::cout << array[i] << " ");
    }

    std::cout << std::endl;
  }
}

template <class T>
class Lower_Triangular_Matrix {
  private :
    const int size;
    const int row_size;
    int *array;

  public :
    // Constructor
    // Using 1D array to save space
    Lower_Triangular_Matrix(int size);

    // Destructor
    ~Lower_Triangular_Matrix();

    // Create the martix
    void create_matrix();

    // change the element of matrix
    void set_matrix();

    // Get the element of the matrix
    T get_element(int i, int j);

    // Display the matrix
    void display_matrix();
};

// Constructor for Lower Triangular Matrix
template <class T>
Lower_Triangular_Matrix<T>::Lower_Triangular_Matrix(int row_size)
: size(row_size * (row_size + 1) / 2), row_size(row_size) {
  array = new T[size];
}

// Destructor for Lower Triangular Matrix
template <class T>
Lower_Triangular_Matrix<T>::~Lower_Triangular_Matrix() {
  delete[] array;
}

// Set the Lower Triangular Matrix
template <class T>
void Lower_Triangular_Matrix<T>::create_matrix() {
  std::cout << "Enter " << size <<  " numbers." << std::endl;

  for (int i = 0; i < size; ++i) {
    std::cin >> this->array[i];
  }
}

// Change the matrix in Lower Triangular Matrix
template <class T>
void Lower_Triangular_Matrix<T>::set_matrix() {
  T element;
  int i, j;

  std::cout << "\nEnter element, row and column." << std::endl;
  std::cin >> element >> i >> j;

  if (i <= 0 || i > row_size || j <= 0 || j > row_size) {
    std::cout << "Out of index" << std::endl;
    std::cout << "Index should be 1 to " << row_size << std::endl;
    return;
  }

  if (i < j) {
    std::cout << "\nCan only change the lower element." << std::endl;
    return;
  }

  this->array[(i - 1) * i / 2 + j - 1] = element;
}

// Get the element from Lower Triangular Matrix
template <class T>
T Lower_Triangular_Matrix<T>::get_element(int i, int j) {
  if (i <= 0 || i > row_size || j <= 0 || j > row_size) {
    std::cout << "Out of index" << std::endl;
    std::cout << "Index should be 1 to " << row_size << std::endl;
    return -1;
  }

  if (i > j) {
    return 0;
  } else {
    return this->array[(i - 1) * i / 2 + j - 1];
  }
}

// Display the Lower Triangular Matrix
template <class T>
void Lower_Triangular_Matrix<T>::display_matrix() {
  for (int i = 1; i <= row_size; ++i) {
    for (int j = 1; j <= row_size; ++j) {
      if (i < j) {
        std::cout << "0 ";
      } else {
        std::cout << array[i * (i - 1) / 2 + j - 1] << " ";
      }
    }

    std::cout << std::endl;
  }
}

template <class T>
class Upper_Triangular_Matrix {
  private :
    int size;
    int row_size;
    T *array;
  public :
    // Constuctor
    Upper_Triangular_Matrix(int row_size);

    // Destructor
    ~Upper_Triangular_Matrix();

    // Create the Matrix
    void create_matrix();

    // change the element of matrix
    void set_matrix();

    // Get the element of the matrix
    T get_element(int i, int j);

    // Display the matrix
    void display_matrix();
};

// Constructor for Upper Triangular Matrix
template <class T>
Upper_Triangular_Matrix<T>::Upper_Triangular_Matrix(int row_size)
: row_size(row_size), size(row_size * (row_size + 1) / 2) {
  array = new T[size];
}

// Destructor for Upper Triangular Matrix
template <class T>
Upper_Triangular_Matrix<T>::~Upper_Triangular_Matrix() {
  delete[] array;
}

// Create matrix for the Upper Triangular matrix
template <class T>
void Upper_Triangular_Matrix<T>::create_matrix() {
  std::cout << "Enter " << size << " numbers." << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cin >> this->array[i];
  }
}

// Change the matrix in Upper Triangular Matrix
template <class T>
void Upper_Triangular_Matrix<T>::set_matrix() {
  T element;
  int i, j;

  if (i <= 0 || i > row_size || j <= 0 || j > row_size) {
    std::cout << "Out of index" << std::endl;
    std::cout << "Index should be 1 to " << row_size << std::endl;
    return;
  }

  if (i > j) {
    std::cout << "\nCan only change the upper element." << std::endl;
    return;
  }

  this->array[(2 * row_size + 2 - i) * (i - 1) / 2 + j - i] = element;
}

// Get element in Upper Triangular Matrix
template <class T>
T Upper_Triangular_Matrix<T>::get_element(int i, int j) {
  if (i <= 0 || i > size || j <= 0 || j > size) {
    std::cout << "Out of index" << std::endl;
    std::cout << "Index should be 1 to " << row_size << std::endl;
    return -1;
  }

  return this->array[(2 * row_size + 2 - i) * (i - 1) / 2 + j - i];
}

// Display the Upper Triangular Matrix
template <class T>
void Upper_Triangular_Matrix<T>::display_matrix() {
  for (int i = 1; i <= row_size; ++i) {
    for (int j = 1; j <= row_size; ++j) {
      if (i > j) {
        std::cout << "0 ";
      } else {
        std::cout << this->array[(2 * row_size + 2 - i) * (i - 1) / 2 + j - i] << " ";
      }
    }

    std::cout << std::endl;
  }
}

template <class T>
class Symmetric_Matrix {
  private :
    int size;
    int row_size;
    T *array;
  public :
    // Constructor
    Symmetric_Matrix(int row_size);

    // Destructor
    ~Symmetric_Matrix();

    // Set the matrix
    void create_matrix();

    // Change the element in the matrix
    void set_matrix();

    // Get the element in the matrix
    T get_element(int i, int j);

    // Display the matrix
    void display_matrix();
};

// Constructor for the Symmetric Matrix
template <class T>
Symmetric_Matrix<T>::Symmetric_Matrix(int row_size)
:row_size(row_size), size(row_size * (row_size + 1) / 2) {
  array = new T[size];
}

// Destructor for the Symmetric Matrix
template <class T>
Symmetric_Matrix<T>::~Symmetric_Matrix() {
  delete[] array;
}

// Create the Symmetric Matrix
template <class T>
void Symmetric_Matrix<T>::create_matrix() {
  std::cout << "Enter " << size << "numbers (from the top and ignore the symmetry)" << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cin >> this->array[i];
  }
}

// Change the matrix in Symmetric Matrix
template <class T>
void Symmetric_Matrix<T>::set_matrix() {
  T element;
  int i, j;

  std::cout << "\nEnter element, row and column." << std::endl;
  std::cin >> element >> i >> j;

  if (i <= 0 || i > row_size || j <= 0 || j > row_size) {
    std::cout << "Out of index" << std::endl;
    std::cout << "Index should be 1 to " << row_size << std::endl;
    return;
  }

  std::cout << "\nIt will change both the symmetric way.\n" << std::endl;

  if (i > j) {
    int temp = i;
    i = j;
    j = temp;
  }

  this->array[(2 * row_size + 2 - i) * (i - 1) / 2 + j - i] = element;
}

// Get element in Symmetric Matrix
template <class T>
T Symmetric_Matrix<T>::get_element(int i, int j) {
  if (i <= 0 || i > size || j <= 0 || j > size) {
    std::cout << "Out of index" << std::endl;
    std::cout << "Index should be 1 to " << row_size << std::endl;
    return -1;
  }

  if (i > j) {
    int temp = i;
    i = j;
    j = temp;
  }

  return this->array[(2 * row_size + 2 - i) * (i - 1) / 2 + j - i];
}

// Display the Symmetric Matrix
template <class T>
void Symmetric_Matrix<T>::display_matrix() {
  for (int i = 1; i <= row_size; ++i) {
    for (int j = 1; j <= row_size; ++j) {
      if (i > j) {
        std::cout << this->array[(2 * row_size + 2 - j) * (j - 1) / 2 + i - j] << " ";
      } else {
        std::cout << this->array[(2 * row_size + 2 - i) * (i - 1) / 2 + j - i] << " ";
      }
    }

    std::cout << std::endl;
  }
}

#endif