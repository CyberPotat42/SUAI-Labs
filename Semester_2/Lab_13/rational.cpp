#include "rational.h"
#include <assert.h>

using namespace std;

Rational::Rational(long long numerator, long long denominator) :
  _numerator(denominator > 0 ? numerator : -numerator),
  _denominator(denominator ? (denominator > 0 ? denominator : -denominator) : 1) {
  assert(denominator != 0);
}

Rational::Rational(const Rational &temp) :
  _numerator(temp._numerator),
  _denominator(temp._denominator) {
}

Rational& Rational::set(long long numerator, long long denominator) {
  _numerator = denominator > 0 ? numerator : -numerator;
  _denominator = denominator ? (denominator > 0 ? denominator : -denominator) : 1;
  return *this;
}

long long& Rational::numerator() {
  return _numerator;
}

long long& Rational::denominator() {
  return _denominator;
}

double Rational::get_value() {
  return (double)_numerator / (double)_denominator;
}

long long gcd(long long a, long long b) {
  if (a == 0) return (b > 0) ? b : -b;
  return gcd(b % a, a);
}

Rational& Rational::simplify() {
  long long factor = gcd(_numerator, _denominator);
  if (_denominator < 0)
    factor *= -1;
  if (factor != 1) {
    _numerator /= factor;
    _denominator /= factor;
  }
  return *this;
}

istream& operator>>(istream &in, Rational &temp) {
  long long num, denom;
  in >> num; in >> denom;
  temp.set(num, denom);
  return in;
}

ostream& operator<<(ostream &out, const Rational &r) {
  out << r._numerator << " / " << r._denominator;
  return out;
}

Rational& Rational::operator=(const Rational &temp) {
  if (this == &temp) return *this;
  _numerator = temp._numerator;
  _denominator = temp._denominator;
  return *this;
} 

Rational& Rational::operator=(const long long &temp) {
  _numerator = temp;
  _denominator = 1;
  return *this;
}

bool operator==(const Rational &r1, const Rational &r2) {
  return (r1._numerator == r2._numerator &&
          r1._denominator == r2._denominator);
}

bool operator!=(const Rational &r1, const Rational &r2) {
  return !(r1 == r2);
}

const Rational Rational::operator+() {
  return Rational(_numerator, _denominator);
}

const Rational Rational::operator-() {
  return Rational(-_numerator, _denominator);
}

Rational& Rational::operator++() {
  _numerator += _denominator;
  return *this;
};

Rational& Rational::operator--() {
  _numerator -= _denominator;
  return *this;
};

Rational Rational::operator++(int) {
  Rational temp(*this);
  ++(*this);
  return temp;
};

Rational Rational::operator--(int) {
  Rational temp(*this);
  --(*this);
  return temp;
};