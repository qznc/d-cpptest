#include <vector>
#include <memory>

#include <main.h>

void d_init();
void d_term();
void registering();

int main () {
  d_init();

  vector<shared_ptr<LineObserver<int> > > obs;
  obs.push_back(make_shared<PostfixPrinter<int> >());

  registering();

  int i = 0;
  for (string line; getline(cin, line); i++) {
    auto begin = obs.begin();
    auto end = obs.end();
    for (; begin != end; ++begin) {
      shared_ptr<LineObserver<int> > ob = *begin;
      ob->observeLine(line, i);
    }
  }

  d_term();
  return 0;
}
