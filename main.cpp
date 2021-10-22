#include <iostream>
#include "math/complex.hpp"

int main() {
    setm::Complex complex{ 3, 5 };
    std::cout << complex.getReal() + 2;
    std::cout << complex << "\n";
    return 0;
}
