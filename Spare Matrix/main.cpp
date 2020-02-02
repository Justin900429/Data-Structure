#include "Sparse_Matrix.h"

int main() {
  int m, n, num;
  std::cout << "Enter the dimension of the sparse matrix." << std::endl;
  std::cin >> m >> n;

  std::cout << "Enter the amount of the none zero elements." << std::endl;
  std::cin >> num;

  Sparse<int> s(m, n, num);
  s.Enter();

  std::cout << s;

  std::cout << "Enter the dimension of the sparse matrix." << std::endl;
  std::cin >> m >> n;

  std::cout << "Enter the amount of the none zero elements." << std::endl;
  std::cin >> num;

  Sparse<int> s2(m, n, num);
  s2.Enter();

  std::cout << s2;

  Sparse<int> *result = add(s, s2);
  Sparse<int> sum = *result;
  delete[] result;
  std::cout << sum;
}