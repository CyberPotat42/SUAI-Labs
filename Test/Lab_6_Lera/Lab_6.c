// Написать функцию, расщепляющую упорядоченный линейный список целых чисел 
// на два упорядоченных списка: простых и составных чисел

#include <stdio.h>
#include "snippets.c"

void main() {
  file *file = read_file("test.txt");
  list *numbers = init_list();
  list *primes = init_list();
  list *composites = init_list();

  parse_file(file, numbers);
  split_primes(numbers, primes, composites);

  printf("%-12s", "numbers:");    print_list(numbers);
  printf("%-12s", "primes:");     print_list(primes);
  printf("%-12s", "composites:"); print_list(composites);
}