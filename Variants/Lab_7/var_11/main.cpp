// Написать генератор псевдослучайных чисел, равномерно распределенных
// на интервале [-5., 5.] (использовать rand()). Подсчитать частоты
// попадания в каждый из интервалов длиной 1 при выборке 500000

// реализовать равномерный закон распределения. у меня нормальный

#include "frand.h"

#define N 5        // границы интервала
#define NUM 500000 // кол-во итераций
#define POWER 6    // коэффициент распределения


int main() {
  // массив [-5., 5.]
  int freq[N * 2] = {0};

  // подсчитываем кол-во появлений
  for (int i = 0; i < NUM; i++)
    freq[round(frand_n(N), N)]++;

  // красиво выводим на экран
  pretty_print(freq, N, 30);
}