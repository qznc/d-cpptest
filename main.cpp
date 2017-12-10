#include <vector>
#include <memory>

#include <main.h>

void d_init();
void d_term();
LineObserver<int>* from_d();

int main () {
  d_init();

  vector<LineObserver<int>*> obs;
  obs.push_back(new PostfixPrinter<int>());

  auto dobj = from_d();
  obs.push_back(dobj);

  int i = 0;
  for (string line; getline(cin, line); i++) {
    auto begin = obs.begin();
    auto end = obs.end();
    for (; begin != end; ++begin) {
      auto ob = *begin;
      ob->observeLine(line.c_str(), i);
    }
  }

  d_term();
  return 0;
}
