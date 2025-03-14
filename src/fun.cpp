// Copyright 2022 UNN-IASR
#include "fun.h"

bool isNum(char);

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

bool isNum(char c) { return c >= '0' && c <= '9'; }

unsigned int faStr2(const char *str) { return 0; }

unsigned int faStr3(const char *str) { return 0; }
