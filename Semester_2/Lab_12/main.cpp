// Создайте класс HugeInt, который хранит в 40-элементном массиве
// цифр целые числа разрядностью до 40 знаков
// Разрядность указать в конструкторе.

// TODO:
// Предусмотреть функции + - == < <= > >= и проверки на 0
// Используйте приватные поля для данных
// определите конструктор, который должен содержать значения по умолчанию
// напишите методы установки и извлечения значений (set, get)
// выполнения операций ввода и вывода значения объекта созданного класса
// Напишите конструктор копий, оператор присваивания, деструктор
// Напишите программу для тестирования вашего класса

//* READY:
// operators: == != < <= > >=

#include <iostream>
#include "HugeInt.h"

using namespace std;

int main() {
  HugeInt test("618");   test.print();
  HugeInt test2("618");  test2.print();
  HugeInt test3("619");  test3.print();
  HugeInt test4("-618"); test4.print();
  // HugeInt test3("619");

  cout << "618 == 618  : " << (test == test2) << endl;
  cout << "618 == 619  : " << (test == test3) << endl;
  cout << "618 == -618 : " << (test == test4) << endl;
  
  cout << "618 != 618  : " << (test != test2) << endl;
  cout << "618 != 619  : " << (test != test3) << endl;
  cout << "618 != -618 : " << (test != test4) << endl;

  cout << "618 < 618  : " << (test < test2) << endl;
  cout << "618 < 619  : " << (test < test3) << endl;
  cout << "618 < -618 : " << (test < test4) << endl;

  cout << "618 <= 618  : " << (test <= test2) << endl;
  cout << "618 <= 619  : " << (test <= test3) << endl;
  cout << "618 <= -618 : " << (test <= test4) << endl;

  cout << "618 > 618  : " << (test > test2) << endl;
  cout << "618 > 619  : " << (test > test3) << endl;
  cout << "618 > -618 : " << (test > test4) << endl;

  cout << "618 >= 618  : " << (test >= test2) << endl;
  cout << "618 >= 619  : " << (test >= test3) << endl;
  cout << "618 >= -618 : " << (test >= test4) << endl;
}

