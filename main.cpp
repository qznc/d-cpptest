#include <vector>
#include <memory>

#include <main.h>

// external D functions
void d_init();
void d_term();
LineObserver<int>* from_d();

int main () {
  d_init(); // init D runtime

  vector<shared_ptr<LineObserver<int> > > obs;
  obs.push_back(make_shared<PostfixPrinter<int> >());
  obs.push_back(shared_ptr<LineObserver<int> >(from_d()));

  int i = 0;
  for (string line; getline(cin, line); i++) {
    for (auto &ob : obs) {
      ob->observeLine(line.c_str(), i);
    }
  }

  d_term(); // shutdown D runtime (necessary?)
  return 0;
}
