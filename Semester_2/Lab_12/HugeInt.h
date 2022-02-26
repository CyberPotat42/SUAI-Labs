#pragma once

#include <vector>
using namespace std;

class HugeInt {
  public:
    HugeInt(int digits = 40);
    void set(int n);
    int get(int n);
    void print();
  
  private:
    vector <unsigned char> array;
    unsigned int i = 0;
    unsigned int digits_count;
};