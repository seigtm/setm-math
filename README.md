# setm::math library

## What is it:

setm::math is a C++ library containing two math classes:

1. [setm::Complex](https://github.com/seigtm/Complex)
   > In mathematics, a polynomial is an expression consisting of variables (also called indeterminates) and coefficients, that involves only the operations of addition, subtraction, multiplication, and non-negative integer exponentiation of variables.  
   > (https://en.wikipedia.org/wiki/Polynomial)
2. [setm::Polynomial](https://github.com/seigtm/Polynomial)
   > In mathematics, a complex number is a number that can be expressed in the form a + bi, where a and b are real numbers, and i is a symbol called the imaginary unit, and satisfying the equation i^2 = -1.  
   > (https://en.wikipedia.org/wiki/Complex_number)

## Supported operators:

### Complex:

- get real and imaginary units;
- unary;
- addition;
- substraction;
- multiplication;
- division;
- exponentiation (using de Moivre's formula);
- nth root (using power);
- trigonometric (sine, cosine and magnitude(abs));
- comparison (equality);
- bitwise (for std::cin and std::cout).

### Polynomial:

- unary;
- addition;
- substraction;
- multiplication;
- division;
- comparison (equality);
- bitwise (for std::cin and std::cout).

## How to use it (examples):

### Complex:

```c++
#include <iostream>

#include <math/complex.hpp>

using namespace setm;

int main() {
    // ((1 - 5 * i) + (1 + 2.1 * i)) == (2 + 7.1 * i) -> true
    std::cout << std::boolalpha << ((Complex(1, -5) + Complex(1, 2.1)) == Complex(2, -2.9)) << "\n";
    // ((3 - 5 * i) + 3.01) == (6.01 - 5 * i) -> true
    std::cout << ((Complex(3, -5) + 3.01) == Complex(6.01, -5)) << "\n";
}
```

```c++
// nrt((64 + 0 * i), 3) == (4 + 0 * i)
std::cout << nrt(Complex(64), 3) << "\n";
// (5 - 5 * i)^2 == (0 - 50 * i)
std::cout << pow(Complex(5, -5), 2) << "\n";
// sin(0 + 1 * i) == (0 + sinh(1) * i)
std::cout << std::boolalpha << (sin(Complex(0, 1)) == Complex(0, std::sinh(1))) << "\n";
// Output: true, as expected.
std::cout << std::boolalpha << (-12.01 == Complex(-12.01)) << "\n";
```

### Polynomial:

```c++
#include <iostream>

#include <math/polynomial.hpp>

using namespace setm;

int main() {
    Polynomial<double> minuend{ 8.2, -3.1, 15.1, 0, 2.2 };
    // subtrahend = x^3 + 15x^2 + 6.1x + 4.2.
    Polynomial<double> subtrahend{ 4.2, 6.1, 15.0, 1 };
    // Output: 2.2x^4 - x^3 + 0.1x^2 - 9.2x + 4.
    std::cout << minuend - subtrahend << "\n";
}
```

```c++
// multiplier = 5x^4 + 4x^3 + 3x^2 + 2x + 1.
Polynomial<int> multiplier{ 1, 2, 3, 4, 5 };
// Output: 25x^4 + 20x^3 + 15x^2 + 10x + 5.
std::cout << 5 * multiplier << "\n";
```

```c++
// first = 8.17x^2 - 15.1x + 3.
std::vector<float> firstData = { 3.0, -15.1, 8.17 };
Polynomial<float> first(firstData.cbegin(), firstData.cend());
// second = 8.17x^2 - 15.1x + 2.
std::vector<float> secondData = { 2.0, -15.1, 8.17 };
Polynomial<float> second{ secondData.cbegin(), secondData.cend() };
// Output: true, as expected.
std::cout << std::boolalpha << (first == (second + 1)) << "\n";
```

## Cloning the repository:

```bash
bash> git clone https://github.com/seigtm/setm-math.git
```

## Build requirements:

- [cmake](https://cmake.org/) to configure the project (minimum required version is **3.5**).
- [conan](https://conan.io/) to download all application dependencies.  
  You can install **conan** by giving a command to **pip**:
  ```bash
  bash> pip install --user conan
  ```
  To use **pip** you need to install the **python** interpreter. I highly recommend to install **python3**-based versions in order to avoid unexpected results when using **conan**.

## Configuring and build with conan and cmake:

To install with `conan`, execute the commands:

1. Install, build and export the setm::math library:
   ```bash
   bash> cd SetmMath
   bash> conan install . -if build --build missing
   bash> cd build
   bash> conan build ..
   bash> conan package ..
   bash> conan export-pkg .. -f
   ```
2. Set up a test project that uses this library and executes several unit tests with `gtest`:
   ```bash
   bash> cd ../..
   bash> conan install . -if build --build missing
   ```

To build and run the project with `cmake`, execute:

```bash
bash> cd build
bash> cmake ..
```

## Project folder structure:

- /SetmMath: Contains setm::math library.
  - /include: Lib headers.
  - /src: Lib sources.
  - CMakeLists.txt
  - conanfile.py
- /ut: Contains gtest unit tests sources.
  - complex_tests.cpp
  - polynomial_tests.cpp
  - polycomplex_tests.cpp
  - CMakeLists.txt
- CMakeLists.txt
- conanfile.py
- main.cpp: Main source, which will run all unit tests from /ut directory.
