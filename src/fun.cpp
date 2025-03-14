// Copyright 2022 UNN-IASR
#include "fun.h"

bool isNum(char);
bool isLetter(char);
bool isCapital(char);

unsigned int faStr1(const char *str) {
  bool inWord = false;
  bool num = false;
  unsigned int count = 0;
  int i = 0;
  while (str[i] != '\0') {
    if (!inWord && str[i] != ' ') {
      inWord = true;
      count++;
    } else if (inWord && str[i] == ' ') {
      inWord = false;
      num = false;
    }
    if (inWord && isNum(str[i]) && !num) {
      num = true;
      count--;
    }
    i++;
  }
  return count;
}

unsigned int faStr2(const char *str) {
  bool inWord = false;
  bool correct = false;
  unsigned int count = 0;
  int i = 0;
  while (str[i] != '\0') {
    if (inWord && !isLetter(str[i]) && correct) {
      count--;
      correct = false;
    }
    if (!inWord && str[i] != ' ') {
      inWord = true;
      if (isCapital(str[i])) {
        count++;
        correct = true;
      }
    } else if (inWord && str[i] == ' ') {
      inWord = false;
      correct = false;
    }
    i++;
  }
  return count;
}

unsigned int faStr3(const char *str) {
  bool inWord = false;
  unsigned int count = 0;
  unsigned int sumLenght = 0;
  int i = 0;
  while (str[i] != '\0') {
    if (!inWord && str[i] != ' ') {
      inWord = true;
      count++;
      sumLenght++;
    } else if (inWord && str[i] == ' ') {
      inWord = false;
    } else if (inWord && str[i] != ' ') {
      sumLenght++;
    }
    i++;
  }
  return sumLenght / count;
}

bool isNum(char c) { return c >= '0' && c <= '9'; }

bool isLetter(char c) { return (c >= 'a' && c <= 'z') || c == ' '; }

bool isCapital(char c) { return c >= 'A' && c <= 'Z'; }
