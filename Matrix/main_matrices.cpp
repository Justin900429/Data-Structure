#include "Matrices.h"

void create(int& size);
void menu(int& choice);

int main() {
  int type;
  while(true) {
    std::cout << "\n---------------------------------------" << std::endl;
    std::cout << "\nType for the array.\n" << std::endl;
    std::cout << "1. Diagonal Matrix" << std::endl;
    std::cout << "2. Lower Triangular Matrix" << std::endl;
    std::cout << "3. Upper Triangular Matrix" << std::endl;
    std::cout << "4. Symmetric Matrix" << std::endl;
    std::cout << "5. Exit\n" << std::endl;
    std::cout << "---------------------------------------\n" << std::endl;
    std::cout << "Enter which type you want" << std::endl;

    std::cin >> type;
    int size;
    if (type == 1) {
      create(size);
      Diagonal_Matrix<int> array(size);
      array.create_matrix();

      int todo;
      while(true) {
        menu(todo);

        if (todo == 1) {
          array.set_matrix();
        }
        else if(todo == 2) {
          int i, j;
          std::cout << "Enter row and column." << std::endl;
          std::cin >> i >> j;
          std::cout << "The element at " << i << " " << j << " is " << array.get_element(i, j) << ".";
        }
        else if(todo == 3) {
          array.display_matrix();
        }
        else if(todo == 4) {
          break;
        } 
        else {
          std::cout << "\nPlease enter the number from the table" << std::endl;
        }
      }
    }
    else if (type == 2) {
      create(size);
      Lower_Triangular_Matrix<int> array(size);
      array.create_matrix();

      int todo;
      while(true) {
        menu(todo);

        if (todo == 1) {
          array.set_matrix();
        }
        else if(todo == 2) {
          int i, j;
          std::cout << "Enter row and column." << std::endl;
          std::cin >> i >> j;
          std::cout << "The element at " << i << " " << j << " is " << array.get_element(i, j) << ".";
        }
        else if(todo == 3) {
          array.display_matrix();
        }
        else if(todo == 4) {
          break;
        } 
        else {
          std::cout << "\nPlease enter the number from the table" << std::endl;
        }
      }
    }
    else if (type == 3) {
      create(size);
      Upper_Triangular_Matrix<int> array(size);
      array.create_matrix();

      int todo;
      while(true) {
        menu(todo);

        if (todo == 1) {
          array.set_matrix();
        }
        else if(todo == 2) {
          int i, j;
          std::cout << "Enter row and column." << std::endl;
          std::cin >> i >> j;
          std::cout << "The element at " << i << " " << j << " is " << array.get_element(i, j) << ".";
        }
        else if(todo == 3) {
          array.display_matrix();
        }
        else if(todo == 4) {
          break;
        } 
        else {
          std::cout << "\nPlease enter the number from the table" << std::endl;
        }
      }
    }
    else if (type == 4) {
      create(size);
      Symmetric_Matrix<int> array(size);
      array.create_matrix();

      int todo;
      while(true) {
        menu(todo);

        if (todo == 1) {
          array.set_matrix();
        }
        else if(todo == 2) {
          int i, j;
          std::cout << "Enter row and column." << std::endl;
          std::cin >> i >> j;
          std::cout << "The element at " << i << " " << j << " is " << array.get_element(i, j) << ".";
        }
        else if(todo == 3) {
          array.display_matrix();
        }
        else if(todo == 4) {
          break;
        } 
        else {
          std::cout << "\nPlease enter the number from the table" << std::endl;
        }
      }
    }
    else if (type == 5) {
      break;
    }
    else {
      std::cout << "Please enter the number from the table." << std::endl;
    }
  } 
}

void create(int& size) {
  std::cout << "Enter the size of the array." << std::endl;
  std::cin >> size;
}

void menu(int &choice) {
  std::cout << "\n---------------------------------------" << std::endl;
  std::cout << "\nTable for function\n" << std::endl;
  std::cout << "1. Change element" << std::endl;
  std::cout << "2. Get element" << std::endl;
  std::cout << "3. Display matrix" << std::endl;
  std::cout << "4. Get back to the last lawyer.\n" << std::endl;
  std::cout << "---------------------------------------\n" << std::endl;
  std::cout << "Enter number for the desired choice." << std::endl;

  std::cin >> choice;
}