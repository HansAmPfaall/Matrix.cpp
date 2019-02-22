#include <chrono>
#include "./Matrix.cpp"

int main(int argc, char const *argv[]) {
  // for (size_t j = 0; j < 10; j++) {
  //   auto start = std::chrono::system_clock::now();
  //   for (size_t i = 0; i < 10000; i++) {
  //     Matrix matrix(30, 80);
  //     // matrix.transpose();
  //     matrix.mult(matrix.transpose());
  //   }
  //   auto end = std::chrono::system_clock::now();
  //   auto elapsed = end - start;
  //   std::cout << elapsed.count() / 1000000000.0 << '\n';
  // }
  // 20.1011 20.0094 19.9936 20.0397
  Matrix matrix(2, 2);
  matrix.print();
  matrix.add(matrix);
  matrix.print();
  return 0;
}