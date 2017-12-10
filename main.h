#include <iostream>

using namespace std;

template <class T>
class LineObserver {
  public:
  virtual void observeLine(const char* line, T payload) = 0;
};

template <class T>
class PostfixPrinter : public virtual LineObserver<T> {
  public:
  virtual void observeLine(const char* line, T payload) {
    cout << line << " " << payload << endl;
  }
};
