#include "Linked_List.h"

Node* add(const int& data, Node* head) {
  if (head == nullptr) {
    Node *next = new Node;
    next->data = data;
    next->next = nullptr;
    return next;
  }

  head->next = add(data, head->next);
  return head;
}

Node* sorted_add(const int& data, Node* head) {
  if (head == nullptr) {
    Node *next = new Node;
    next->data = data;
    next->next = nullptr;
    return next;
  }
  else if (head->data > data) {
    Node* next = new Node;
    next->data = data;
    next->next = head;
    return next;
  }

  head->next = sorted_add(data, head->next);
  return head;
}

Node* insert(const int& data, Node *head, int place) {
  // Using static to remember the place
  static int count = 1;

  if (place == 0) {
    Node* next = new Node;
    next->data = data;
    next->next = head;
    return next;
  }
  else if (place == count) {
    Node* next = new Node;
    next->data = data;
    next->next = head->next;
    head->next = next;
    count = 1;
    return head;
  }

  count++;
  head->next = insert(data, head->next, place);
  return head;
}

Node* delete_node(Node* head, int place) {
  // Use static to remember the place
  static int count = 1;

  if(place == count) {
    Node* temp = head->next;
    delete head;
    count = 1;
    return temp;
  }

  ++count;
  head->next = delete_node(head->next, place);
  return head;
}

void display(const Node* head) {
  if (head == nullptr) {
    std::cout << std::endl;
    return;
  }

  std::cout << head->data << " ";
  display(head->next);
}

int count(const Node* head) {
  if (head == nullptr) {
    return 0;
  } else {
    return count(head->next) + 1;
  }
}

int sum(const Node* head) {
  if (head == nullptr) {
    return 0;
  } else {
    return sum(head->next) + head->data;
  }
}

int find_max(Node* head) {
  if (head->next == nullptr) {
    return head->data;
  }

  int x = find_max(head->next);
  return (head->data > x)? head->data : x;
}

int find_min(Node* head) {
  if (head->next == nullptr) {
    return head->data;
  }

  int x = find_min(head->next);
  return (head->data < x)? head->data : x;
}

bool is_sorted(Node* head) {
  Node* temp = head->next;
  int x = head->data;

  while(temp != nullptr) {
    if (x > temp->data) {
      return false;
    }
    x = temp->data;
  }
  return true;
}

// In order to improve the Linear Search, using move to head
Node* linear_search(Node* head, Node* prev, int tar) {
  if (head == nullptr) {
    return nullptr;
  }
  else if (head->data == tar) {
    prev->next = head->next;
    return head;
  }

  return linear_search(head->next, head, tar);
}

void remove_duplicate(Node* head) {
  Node *p = head, *q, *temp;

  while (p != nullptr) {
    q = p->next;
    temp = p;
    while(q != nullptr) {
      if (p->data == q->data) {
        temp->next = q->next;
        delete q;
        q = temp->next;
      } else {
        temp = q;
        q = q->next;
      }
    }
    p = p->next;
  }
}

Node* reverse_linked_list(Node* head) {
  Node* p = head, *q = nullptr, *r = nullptr;
  
  while (p != nullptr) {
    q = p;
    p = p->next;
    q->next = r;
    r = q;
  }

  return q;
}

Node* concatate(Node* first, Node* second) {
  Node* temp = first;
  while(temp->next !=  nullptr) {
    temp = temp->next;
  }

  temp->next = second;
  return first;
}

Node* merge(Node* first, Node* second) {
  Node *result, *record;
  if (first->data > second->data) {
    result = record = second;
    second = second->next;
    record->next = nullptr;
  } else {
    result = record = first;
    first = first->next;
    record->next = nullptr;
  }

  while (first != nullptr && second != nullptr) {
    if (first->data < second->data) {
      record->next = first;
      first = first->next;
      record = record->next;
      record->next = nullptr;
    } else {
      record->next = second;
      second = second->next;
      record = record->next;
      record->next = nullptr;
    }
  }

  if (first == nullptr) {
    record->next = second;
  } else {
    record->next = first;
  }

  return result;
}

bool is_loop(Node* head) {
  Node *p = head, *q = head;

  do {
    p = p->next;
    q = q->next;
    q = (q == nullptr)? q : q->next;
  } while (q != nullptr && q != nullptr && p != q);

  if (p == q) {
    return true;
  } else {
    return false;
  }
  
}

// Suppose the place had been preprocessing before calling the function
Node* add_circular(Node* head, const int& data, const int& place) {
  // Use static to record the position
  static int count = 0;

  if (place == 0) { // Check if the position is before the head
    Node* p = head;
    while(p->next != head) {
      // Reach the last node
      p = p->next;
    }
    Node* next = new Node;
    next->data = data;
    next->next = head;
    p->next = next;
    return next;
  } 
  else if (place == count) {  // Reach the position
    Node* next = new Node;
    next->data = data;
    next->next = head->next;
    return next;
  }

  ++count;
  head->next = add_circular(head->next, data, place);
  return head;
}

Node* delete_circular(Node* head, const int& place) {
  static int count = 1;
  if (place == 1) {
    Node* p = head;
    while (p->next != head) {
      // Reach the last node
      p = p->next;
    }
    p->next = head->next;

    // Remember the node
    Node* temp = head->next;

    // Delete the old node
    delete head;
    return temp;
  } 
  else if (place == count) {
    Node* temp = head->next;
    delete head;
    return temp;
  }

  count++;
  head->next = delete_circular(head->next, place);
  return head;
}

Double_Node* add_double(Double_Node* head, const int& data) {
  Double_Node *p = head, *prev = nullptr;
  while (p != nullptr) {
    prev = head;
    head = head->next;
  }

  Double_Node* next = new Double_Node;
  next->data = data;
  next->next = nullptr;
  next->prev = prev;
  return head;
}

int count_double(Double_Node* head) {
  int count = 0;

  // Until reach the nullptr
  for (int i = 0; head != nullptr; ++i) {
    count++;
  }

  return count;
}

Double_Node* insert_double(Double_Node* head, const int& data, const int& place) {
  if (place > count_double(head)) {
    std::cout << "Out of boundry." << std::endl;
    return head;
  }
  else if (place == 0) {
    Double_Node* node = new Double_Node;
    node->data = data;
    node->next = head;
    node->prev = nullptr;
    return node;
  } else {
    Double_Node* p = head;

    // Record the place
    for (int count = 1; count < place; ++count) {
      p = p->next;
    }

    Double_Node* node = new Double_Node;
    node->data = data;
    node->next = p->next;
    node->prev = p;
    if (p->next != nullptr) {
      p->next->prev = node;
    }
    p->next = node;
    return head;
  }
}

Double_Node* delete_double(Double_Node* head, const int& place) {
  if (place > count_double(head)) {
    std::cout << "Out of boundry." << std::endl;
    return head;
  }
  else if (place == 0) {
    if (head != nullptr) {
      head->next->prev = nullptr;
      return head->next;
    }
  } else {
    Double_Node *p = head;

    // Record the place
    int count = 0;
    for (int i = 0; i < place; ++i) {
      p = p->next;
    }

    p->prev->next = p->next;
    if (p->next != nullptr) {
      p->next->prev = p->prev;
    }

    delete p;
    return head;
  }
}

Double_Node* reverse_double(Double_Node* head) {
  Double_Node *temp, *p;
  Double_Node* result;

  while (p != nullptr) {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;
    if (p != nullptr && p->next == nullptr) {
      result = p;
    }
  }

  return result;
}

void free(Node* head) {
  if (head == nullptr) {
    return;
  }

  free(head->next);
  delete head;
}