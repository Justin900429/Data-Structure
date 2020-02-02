#ifndef SPARSE_MATIRX_H
#define SPARSE_MATIRX_H

#include <iostream>

template <typename T>
struct Element {
  // the position i, j  and the number in that position
  int i, j;
  T element;
};

template <class T>
class Sparse {
  private :
    // Dimension of array
    int m, n;

    // None zero element
    int num;

    // Array of element
    Element<T> *e;

  public:
    // Constructor for the class
    Sparse(int m, int n, int num);

    // Destructor for the class
    ~Sparse();

    // Enter element into the matrix
    void Enter();

    // For cout the matrix
    template <class U>
    friend std::ostream& operator<<(std::ostream& ouput, const Sparse<U>& sparse);

    // Add two sparser matrix
    template <class U>
    friend Sparse<U>* add(const Sparse<U>& s1, const Sparse<U>& s2);
};

// Constructor for the class
template <class T>
Sparse<T>::Sparse(int m, int n, int num)
: m(m), n(n), num(num) {
  e = new Element<T>[num];
}

// Destructor for the class
template <class T>
Sparse<T>::~Sparse() {
  delete[] e;
}

// Enter element into the matrix
template <class T>
void Sparse<T>::Enter() {
  std::cout << "\nPlease enter none zero element." << std::endl;

  for (int i = 0; i < this->num; ++i) {
    std::cin >> this->e[i].i  >> this->e[i].j >> this->e[i].element;
  }
}

template <class T>
std::ostream& operator<<(std::ostream& output, const Sparse<T>& sparse) {
  // Record where the none zero elements are reach
  int k = 0;;

  output << std::endl;
  for (int i = 0; i < sparse.m; ++i) {
    for (int j = 0; j < sparse.n; ++j) {
      if (i == sparse.e[k].i && j == sparse.e[k].j) {
        output << sparse.e[k++].element << " ";
      } else {
        output << "0 ";
      }
    }

    output << std::endl;
  }

  return output;
}

template <class T>
Sparse<T>* add(const Sparse<T>& s1, const Sparse<T>& s2) {
  if (s1.m != s2.m || s1.n != s2.n) {
    return 0;
  }

  Sparse<T> *sum = new Sparse<T>(s1.m, s1.n, s1.num + s2.num);

  int i = 0, j = 0, k = 0;
  while (i < s1.num && j < s2.num) {
    if (s1.e[i].i < s2.e[j].i) {
      sum->e[k++] = s1.e[i++];
    }
    else if (s2.e[j].i < s1.e[i].i) {
      sum->e[k++] = s2.e[j++];
    }
    else if (s1.e[i].j < s2.e[j].j) {
      sum->e[k++] = s1.e[i++];
    }
    else if (s2.e[j].j < s1.e[i].j) {
      sum->e[k++] = s2.e[j++];
    }
    else {
      sum->e[k] = s1.e[i++];
      sum->e[k++].element += s2.e[j++].element;
    }
  }

  for (; i < s1.num; ++i) {
    sum->e[k++] = s1.e[i];
  }
  for (; j < s2.num; ++j) {
    sum->e[k++] = s2.e[j];
  }

  sum->num = k;
  return sum;
}
#endif