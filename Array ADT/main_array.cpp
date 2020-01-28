#include "Array.h"

int main() {
  std::cout << "Enter the total size of the array" << std::endl;
  int size = 0;
  std::cin >> size;

  std::cout << "\nEnter the total number going to enter (Should smaler than size)" << std::endl; 
  int length = 0;
  std::cin >> length;

  Array arr(size, length);
  std::cout << "\nEnter the elements of the array" << std::endl;
  std::cin >> arr;

  int choice;
  do {
    std::cout << "\nMenu" << std::endl;
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Search" << std::endl;
    std::cout << "4. Sum" << std::endl;
    std::cout << "5. Display" << std::endl;
    std::cout << "6. Exit\n" << std::endl;
    std::cout << "Enter the number to get the choice." << std::endl;

    std::cin >> choice;
    int index = 0, element = 0;

    switch (choice) {
      case 1:
        std::cout << "\nEnter the index and element to insert" << std::endl;
        std::cin >> index >> element;
        arr.insert(index, element);
        break;
      case 2:
        std::cout << "\nEnter the index to delete" << std::endl;
        std::cin >> element;
        arr.del(element);
        break;
      case 3:
        std::cout << "\nEnter the element to search" << std::endl;
        std::cin >> element;
        if (arr.binarySearch(element) != -1) {
          std::cout << "\nThe element of " << element << " is at index " << arr.binarySearch(element) << std::endl;
        } else {
          std::cout << "\nElement not found." << std::endl;
        }
        break;
      case 4:
        std::cout << "\nThe sum of an array is " << arr.getSum() << "." << std::endl;
        break;
      case 5:
        std::cout << "\nThe element inside array is " << std::endl;
        std::cout << arr;
        break;
      default:
        break;
    }
  } while (choice != 6);
}