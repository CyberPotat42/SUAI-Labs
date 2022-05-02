// Создайте класс SqrMatrix
// (квадратная матрица с элементами типа double)
// с операциями + - * /, умножения на скаляр
// Размерность матрицы задать в конструкторе

// TODO:
//* Используйте приватные поля для данных
//* Реализуйте конструктор, который должен устанавливать значения по умолчанию, 
// Реализуйте методы для чтения и записи значений полей (set, get), а также ввода и вывода (перегрузка operator<< и operator>> не требуется)
// Если требуется, напишите конструктор копий, оператор присваивания и деструктор 
// Напишите программу для тестирования вашего класса

#include <vector>
#include <iostream>
#include <cstdlib> // для exit()

using namespace std;

unsigned int get_size(vector <vector <double>> arr) {
  unsigned int size = arr.size();
  for (int i = 0; i < size; i++) {
    if (arr[i].size() != size) {
      return 0;
    }
  }
  return size;
}

class Matrix {
  private:
    vector <vector <double>> arr;

  public:
    Matrix(unsigned int size = 1) {
      try {
        if (size > 0) {
          arr.resize(size);
          for (int i = 0; i < size; i++) {
            arr[i].resize(size);
          }
        } else {
          throw "Matrix is not square!";
        }
      } catch (const char *s) {
        cerr << "Error in class constructor: " << s << endl;
        exit(1);
      }
    }
    
    Matrix(vector <vector <double>> temp) : Matrix (get_size(temp)) {
      arr = temp;
    }

    Matrix& set(int x, int y, double value) {}
    Matrix& set(vector <vector <double>> a) {}

    double get(int x, int y) {}

    void print() {
      for (int y = 0; y < arr.size(); y++) {
        for (int x = 0; x < arr[y].size(); x++)
          cout << arr[y][x] << " ";
        cout << endl;
      }
      cout << endl;
    }
};

int main() {
  Matrix m1;
  m1.print();

  Matrix m2(10);
  m2.print();

  Matrix m3(
    {
      {1, 2, 3, 4},
      {1, 2, 3, 4},
      {1, 2, 3, 4},
      {1, 2, 3, 4},
    }
  );
  m3.print();

  Matrix m4(m3);
  m4.print();

  Matrix m5(
    {
      {1, 2},
      {3, 4}
    }
  );
  m5.print();

  m5 = m3;
  m5.print();

  Matrix m6(
    {
      {1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
    }
  );
  m6.print();
}