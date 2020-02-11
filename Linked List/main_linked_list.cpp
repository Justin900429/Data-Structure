#include "Linked_List.h"

void menu(int& choice);

int main() {
  int choice;
  menu(choice);
  Node* head = nullptr;

  while(choice != 12) {
    if (choice == 1) {
      int data;
      std::cout << "\nEnter the data." << std::endl;
      std::cin >> data;
      head = add(data, head);
    }
    else if (choice == 2) {
      std::cout << std::endl;
      display(head);
    }
    else if (choice == 3) {
      int data, place;
      std::cout << "\nEnter the place and the data to insert" << std::endl;
      std::cin >> place >> data;

      // Check the boundry
      if (place > count(head) || place < 0) {
        std::cout << "\nOut of boundry." << std::endl;
      } else { 
        head = insert(data, head, place);
      }
    }
    else if (choice == 4) {
      int place;
      std::cout << "\nEnter the place to delete" << std::endl;
      std::cin >> place;

      // Check the boundry
      if (place > count(head) || place <= 0) {
        std::cout << "\nOut of boundry." << std::endl;
      } else { 
        head = delete_node(head, place);
      }
    }
    else if (choice == 5) {
      head = reverse_linked_list(head);
      std::cout << "\nAlready reverse the Linked List." << std::endl;
    }
    else if (choice == 6) {
      std::cout << "\nThe sum of the linked list is " << sum(head) << "." << std::endl;
    }
    else if (choice == 7) {
      int amount = count(head);
      if (amount <= 1) {
        std::cout << "\nThere is " << amount << " element in the linked list." << std::endl;
      } else {
        std::cout << "\nThere are " << amount << " elements in the linked list." << std::endl;
      }
    }
    else if (choice == 8) {
      if (head != nullptr) {
        std::cout << "\nThe maximin number in Linked List is " << find_max(head) << "." << std::endl;
      } else {
        std::cout << "\nNo element in the Linked List." << std::endl;
      }
    }
    else if (choice == 9) {
      if (head != nullptr) {
        std::cout << "\nThe minimum number in Linked List is " << find_min(head) << "." << std::endl;
      } else {
        std::cout << "\nNo element in the Linked List." << std::endl;
      }
    }
    else if (choice == 10) {
      remove_duplicate(head);
      std::cout << "\nAlready remove duplicate element." << std::endl;
    }
    else if (choice == 11) {
      int tar;
      std::cout << "\nEnter the element going to search." << std::endl;
      std::cin >> tar;

      Node *p = linear_search(head, head, tar);
      if (p == nullptr) {
        std::cout << "\nElement not found" << std::endl;
      } else {
        if (head != p) {
          p->next = head;
          head = p;
        }
        std::cout << "\nElement " << tar << " had been found." << std::endl;
      }
    }
    else {
      std::cout << "\nPlease enter the correct command." << std::endl;
    }

    menu(choice);
  }

  free(head);
}

void menu(int& choice) {
  std::cout << "\n-----------------------" << std::endl;
  std::cout << "Table for the function:\n" << std::endl;
  std::cout << "1. Add new node" << std::endl;
  std::cout << "2. Display" << std::endl;
  std::cout << "3. Insert" << std::endl;
  std::cout << "4. Delete" << std::endl;
  std::cout << "5. Reverse" << std::endl;
  std::cout << "6. Sum" << std::endl;
  std::cout << "7. Count" << std::endl;
  std::cout << "8. Max" << std::endl;
  std::cout << "9. Min" << std::endl;
  std::cout << "10. Remove duplicate element" << std::endl;
  std::cout << "11. Search" << std::endl;
  std::cout << "12. Quit" << std::endl;
  std::cout << "\nEnter your choice." << std::endl;
  std::cin >> choice;
  std::cout << "-----------------------\n" << std::endl;
}