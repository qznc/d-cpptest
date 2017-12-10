#include <iostream>
#include <string>

using namespace std;

template <class T>
class LineObserver {
  public:
  virtual void init(T x) = 0;
  virtual void observeLine(string line) = 0;
};

template <class T>
class PrefixPrinter : virtual LineObserver<T> {
  T prefix;
  public:
  virtual void init(T x) {
    prefix = x;
  }
  virtual void observeLine(string line) {
    cout << prefix << line << endl;
  }
};
