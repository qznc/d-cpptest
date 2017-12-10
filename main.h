#include <iostream>
#include <string>

using namespace std;

template <class T>
class LineObserver {
  public:
  virtual void observeLine(string line, T payload) const = 0;
};

template <class T>
class PostfixPrinter : public virtual LineObserver<T> {
  public:
  virtual void observeLine(string line, T payload) const {
    cout << line << " " << payload << endl;
  }
};
