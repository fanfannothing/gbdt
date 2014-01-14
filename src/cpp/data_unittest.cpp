#include "data.hpp"
#include <iostream>
#include <cassert>

using namespace gbdt;

int main(int argc, char *argv[]) {
  std::string l = "1 2 0:10 1:100";
  gConf.number_of_feature = 3;
  gConf.max_depth = 4;

  Tuple *t = Tuple::FromString(l);

  std::cout << t->ToString() << std::endl;

  DataVector d;
  bool r = LoadDataFromFile("../../data/test.dat", &d);
  assert(r);
  DataVector::iterator iter = d.begin();
  for ( ; iter != d.end(); ++iter) {
    std::cout << (*iter)->ToString() << std::endl;
  }

  CleanDataVector(&d);
  return 0;
}
