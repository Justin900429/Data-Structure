#ifndef STRING_H
#define STRING_H

#include<iostream>

void swap(char& a, char& b);

class String {
  private :
    char *s;
    int length;

    // Count the length of the length
    void countLength();

  public :
    // Constructor for the String class
    String(const char* string);

    // Destructor for String class
    ~String();
    
    // Return the length of the string
    int getLength();

    // Change to upper case
    void toUpper();

    // Change to lower case
    void toLower();

    // Toggle the case
    void toggleCase();

    // Count how many words in String
    int countWords();

    // Check whether the string is valid to us(valid only for vocabulary)
    void checkValid();

    // Reverse the string
    void reverseString();

    // Check panlidrom
    int isPalindrom();

    // Find duplicate using array
    void findDuplicate();

    // Find duplicate character using bitwise operation(only for vacabulary and suppose there are no duplicate);
    void findDuplicateBitwise();

    // Ostream overload
    friend std::ostream& operator << (std::ostream &output, const String& str);

    // Compare two string
    friend int compare(const String& str1, const String& str2);

    // Check if two string is anagram
    friend void checkAnagram(const String& str1, const String& str2);

    // Permutation of the string using Static
    friend void permutationWithStatic(const String& str, int k);

    // Permutaion of the string using swap
    friend void permutationWithSwap(const String& str, int l , int h);
};

#endif