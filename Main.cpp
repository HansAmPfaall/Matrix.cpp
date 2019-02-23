#include <chrono>
#include "./Matrix.h"

int main(int argc, char const *argv[]) {
  // for (size_t j = 0; j < 10; j++) {
  //   auto start = std::chrono::system_clock::now();
  //   for (size_t i = 0; i < 10000; i++) {
  //     Matrix matrix(30, 80);
  //     matrix.mult(matrix.t());
  //   }
  //   auto end = std::chrono::system_clock::now();
  //   auto elapsed = end - start;
  //   std::cout << elapsed.count() / 1000000000.0 << '\n';
  // }
  // 20.1011 20.0094 19.9936 20.0397
  // Matrix a(2, 3);
  // a.print();
  // a.setValue(0, 0, 2);
  // a.setValue(0, 1, 5);
  // a.setValue(0, 2, 6);
  // a.setValue(1, 0, 1);
  // a.setValue(1, 1, 4);
  // a.setValue(1, 2, 7);
  // a.print();
  // std::cout << "/* message */" << std::endl;
  // Matrix b(3, 2);
  // b.setValue(0, 0, 7);
  // b.setValue(0, 1, 5);
  // b.setValue(1, 0, 41);
  // b.setValue(1, 1, 6);
  // b.setValue(2, 0, 3);
  // b.setValue(2, 1, 2);
  // b.print();
  // std::cout << "/* message */" << std::endl;
  // // matrix.setValue(0, 3, 10);
  // (a*b).print();
  return 0;
}