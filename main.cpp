#include <vector>
#include <memory>

#include <main.h>

int main () {
  vector<shared_ptr<LineObserver<int> > > obs;
  obs.push_back(make_shared<PostfixPrinter<int> >());

  int i = 0;
  for (string line; getline(cin, line); i++) {
    auto begin = obs.begin();
    auto end = obs.end();
    for (; begin != end; ++begin) {
      shared_ptr<LineObserver<int> > ob = *begin;
      ob->observeLine(line, i);
    }
  }
  return 0;
}
