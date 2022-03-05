// Написать функцию, расщепляющую упорядоченный линейный список целых чисел 
// на два упорядоченных списка: простых и составных чисел

#include <stdio.h>
#include "snippets.c"

void main() {
  // открываем и считываем файл
  file *file = read_file("test.txt");

  // инициализируем списки чисел
  list *numbers = init_list();
  list *primes = init_list();
  list *composites = init_list();

  // парсим числа из файла и разделяем их
  parse_file(file, numbers);
  split_primes(numbers, primes, composites);

  // выводим на экран
  printf("\nnumbers:\n");
  print_list(numbers);
  printf("\nprimes:\n");
  print_list(primes);
  printf("\ncomposites:\n");
  print_list(composites);

  // очищаем память
  destroy(numbers);
  destroy(primes);
  destroy(composites);
}