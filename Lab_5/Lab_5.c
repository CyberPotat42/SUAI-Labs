// ������ ������. �������� ����� ���������� �� ����������
// ('.' - ���, ',' - ���, '?' - ���, ':' - ���)


#define USE_RUS 1  // 1 - yes
// If cyrillic symbols are broken: ctrl + shift + P
// -> Change file rncoding -> Reopen with encoding -> Windows 1251

#include <stdio.h>
#include <stdlib.h>
#if USE_RUS == 1
#include <locale.h>
#endif

#define length(x) (sizeof(x) / sizeof((x)[0]))
int len = 0;

char *readstr() {
  len = 0;
  int capacity = 1;                       // ������� ������������ ������
  char *s = (char *)malloc(sizeof(char)); // ������������ ������ ������
  char c = getchar();
  while (c != '\n') {
    s[(len)++] = c;
    if (len >= capacity) {                             // ���� �������� ������ ������ ������� ����������, �� �������� ��� ������
      capacity *= 2;                                   // ����������� ������� � ��� ����
      s = (char *)realloc(s, capacity * sizeof(char)); // ������ ����� ������ � ����������� ��������
    } c = getchar(); }
  s[len] = '\0';
  return s; // ���������� ���������
}

void print_char(char ch) {
  switch (ch) {
    case '.': printf(USE_RUS == 1 ? "���" : "DOT"); break;
    case ',': printf(USE_RUS == 1? "���" : "COMMA"); break;
    case '!': printf(USE_RUS == 1 ? "����" : "EXCLM"); break;
    case '?': printf(USE_RUS == 1 ? "����" : "QSTN"); break;
    case ':': printf(USE_RUS == 1 ? "����" : "COLON"); break;
    default: printf("%c", ch); break;
  }
}

void main() {
  #if USE_RUS == 1
  setlocale(LC_ALL, "Russian");
  system("chcp 1251");
  #endif

  printf(USE_RUS == 1 ? "������� ������:\n" : "Input string:\n");
  char *str = readstr(); // ��������� ������������ ������
  printf(USE_RUS == 1 ? "\n������ ����� ������:\n" : "\nString after replace:\n");
  for (int i = 0; i < len; i++) print_char(str[i]);
  free(str);
}
