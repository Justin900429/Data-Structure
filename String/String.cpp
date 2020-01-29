#include "String.h"

void swap(char& a, char& b)  {
  char temp = a;
  a = b;
  b = temp;
}

String::String(const char* string) {
  int i;
  for (i = 0; string[i] != '\0'; ++i) {
  }

  this->s = new char[i + 1];

  for (int j = 0; j <= i; ++j) {
    this->s[j] = string[j];
  }

  this->length = i;
}

String::~String() {
  delete[] this->s;
  std::cout << "Destructor called" << std::endl;
}

void String::countLength() {
  int i;
  for (i = 0; this->s[i] != '\0'; ++i) {

  }

  this->length = i;
}

int String::getLength() {
  return this->length;
}

void String::toUpper() {
  for (int i = 0; this->s[i] != '\0'; ++i) {
    if (this->s[i] > 'A' && this->s[i] < 'Z') {
      continue;
    }
    this->s[i] -= 32;
  }
}

void String::toLower() {
  for (int i = 0; this->s[i] != '\0'; ++i) {
    if (this->s[i] > 'a' && this->s[i] < 'z') {
      continue;
    }
    this->s[i] += 32;
  }
}

void String::toggleCase() {
  for (int i = 0; this->s[i] != '\0'; ++i) {
    if (this->s[i] > 'A' && this->s[i] < 'Z') {
      this->s[i] += 32;
    }
    else if (this->s[i] > 'a' && this->s[i] < 'z') {
      this->s[i] -= 32;
    }
  }
}

int String::countWords() {
  int words = 0;

  for (int i = 0; this->s[i] != '\0'; ++i) {
    if (this->s[i] == ' ' && this->s[i - 1] != ' ') {
      words++;
    }
  }

  return words;
}

void String::checkValid() {
  for (int i = 0; this->s[i] != '\0'; ++i) {
    if (!((this->s[i] >= 'a' && this->s[i] <= 'z') || (this->s[i] >= 'A' && this->s[i] <= 'Z'))) {
      std::cout << "Invalid string!" << std::endl;
      return;
    }
  }

  std::cout << "Valid string!" << std::endl;
}

void String::reverseString() {
  for (int i = 0, j = this->length - 1; i < j; ++i, --j) {
    swap(this->s[i], this->s[j]);
  }
}

int String::isPalindrom() {
  for (int i = 0, j = this->length - 1; i < j; ++i, --j) {
    if (this->s[i] != this->s[j]) {
      return -1;
    }
  }
  return 1;
}

void String::findDuplicate() {
  int test[26] = {0};

  for (int i = 0; i < this->length; ++i) {
    test[this->s[i] - 97]++;
  }

  for (int i = 0; i < 26; ++i) {
    if (test[i] > 1) {
      std::cout << "'" << (char)(i + 97) << "'" << " is duplicate." << std::endl;
    }
  }
}

void String::findDuplicateBitwise() {
  int h = 0, x = 0, flag = 0;
  for (int i = 0; i < this->length; ++i) {

    x = 1;
    x <<= (int)(this->s[i] - 97);

    if ((h & x) != 0) {
      flag = 1;
      std::cout << "'" << this->s[i] << "'" << " is duplicate." << std::endl;
    } else {
      h = h | x;
    }
  }

  if (flag == 0) {
    std::cout << "No duplicate." << std::endl;
  }
}

std::ostream& operator << (std::ostream &output, const String& str) {
  output << str.s << std::endl;
  return output;
}

int compare(const String& str1, const String& str2) {
  int i, j;
  for (i = 0, j = 0; str1.s[i] != '\0' && str2.s[j] != '\0'; ++i, ++j) {
    if (str1.s[i] > str2.s[j]) {
      return 1;
    }
    else if (str1.s[i] < str2.s[j]) {
      return -1;
    }
  }

  if (str1.s[i] == '\0') {
    return -1;
  }
  else if (str2.s[j] == '\0') {
    return 1;
  }

  return 0;
}

void checkAnagram(const String& str1, const String& str2) {
  int temp[26] = {0};

  for (int i = 0; i < str1.length; ++i) {
    temp[str1.s[i] - 97]++;
  }

  for (int i = 0; i < str2.length; ++i) {
    temp[str2.s[i] - 97]--;
    if (temp[str2.s[i] - 97] < 0) {
      std::cout << "They are not anagram." << std::endl;
      return;
    }
  }

  std::cout << "They are anagram." << std::endl;
}

void permutationWithStatic(const String& str, int k) {
  static int check[20];
  static char out[20];

  if (k == str.length) {
    out[str.length] = '\0';
    std::cout << out << std::endl;
  } else {
    for (int i = 0; i < str.length; ++i) {
      if (check[i] == 0) {
        out[k] = str.s[i];
        check[i] = 1;
        permutationWithStatic(str, k + 1);
        check[i] = 0;
      }
    }
  }
}

void permutationWithSwap(const String& str, int l , int h) {
  if (l == h) {
    std::cout << str;
  } else {
    for (int i = l; i <= h; ++i) {
      swap(str.s[i], str.s[l]);
      permutationWithSwap(str, l + 1, h);
      swap(str.s[i], str.s[l]);
    }
  }
}