#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>

class Node {
  public :
    int data;
    Node* next;
};

class Double_Node {
  public :
    int data;
    Double_Node* next;
    Double_Node* prev;
};

// Add a new node into the Linked List
Node* add(const int& data, Node* head);

// Add a new node into the Linked List in order
Node* sorted_add(const int& data, Node* head);

// Insert a node in a wanted place
Node* insert(const int& data, Node* head, int place);

// Delete a node in a wanted place
Node* delete_node(Node* head, int place);

// Display the linked List
void display(const Node* head);

// Count how many node inside the Linked List
int count(const Node* head);

// Sum all the node data in the Linked List
int sum(const Node* head);

// Find the max element in Linked List
int find_max(Node* head);

// Find the min element in Linked List
int find_min(Node* head);

// Check whether the Linked List is sorted or not
bool is_sorted(Node* head);

// Remove the duplicate node
void remove_duplicate(Node* head);

// Reverse the Linked List
Node* reverse_linked_list(Node* head);

// Concatate two Linked List
Node* concatate(Node* first, Node* second);

// Merge two Linked List
Node* merge(Node* first, Node* second);

// Check if the Linked List is Linear or not
bool is_loop(Node* head);

// Search the element in the Linked List
Node* linear_search(Node* head, Node* prev, int tar);

// Add new node to circular Linked List
Node* add_circular(Node* head, const int& data, const int& place);

// Delete node from circular Linked List
Node* delete_circular(Node* head, const int& place);

// Add new node into double Linked List
Double_Node* add_double(Double_Node* head, const int& data);

// Count how many node does Linked List have
int count_double(Double_Node* head);

// Insert new node to where the user want
Double_Node* insert_double(Double_Node* head, const int& data, const int& place);

// Delete the node where the user want
Double_Node* delete_double(Double_Node* head, const int& place);

// Reverse the double Linked List
Double_Node* reverse_double(Double_Node* head);

#endif