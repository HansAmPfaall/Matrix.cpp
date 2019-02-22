#include "./Matrix.h"

int main(int argc, char const *argv[]) {
    std::cout << "/* message */" << std::endl;
    Matrix matrix(2, 5);
    // matrix.print();
    matrix.transpose().print();
    // matrix.print();
    return 0; 
}