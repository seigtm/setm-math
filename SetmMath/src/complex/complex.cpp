#include <cmath>
#include <iostream>
#include <limits>

#include "math/complex.hpp"

namespace setm {

Complex::Complex()
    : real{}, img{} {
}

Complex::Complex(double r, double i)
    : real{ r }, img{ i } {
}

Complex &Complex::operator+=(const Complex &other) {
    real += other.real;
    img += other.img;
    return *this;
}

Complex Complex::operator+(double value) const {
    Complex result{ *this };
    return (result += value);
}

Complex Complex::operator-() const noexcept {
    return { -real, -img };
}

Complex Complex::operator+() const noexcept {
    return *this;
}

Complex &Complex::operator-=(const Complex &other) {
    real -= other.real;
    img -= other.img;
    return *this;
}

Complex Complex::operator-(double value) const {
    Complex result{ *this };
    return (result -= value);
}

Complex &Complex::operator*=(const Complex &other) {
    const double tempReal{ real * other.real - img * other.img };
    const double tempImg{ img * other.real + real * other.img };
    real = tempReal;
    img = tempImg;
    return *this;
}

Complex Complex::operator*(double value) const {
    Complex result{ *this };
    return (result *= value);
}

Complex &Complex::operator/=(const Complex &other) {
    const double tempReal{ ((real * other.real) + (img * other.img)) / (other.real * other.real + other.img * other.img) };
    const double tempImg{ ((img * other.real) - (real * other.img)) / (other.real * other.real + other.img * other.img) };
    real = tempReal;
    img = tempImg;
    return *this;
}

Complex Complex::operator/(double value) const {
    Complex result{ *this };
    return (result /= value);
}

SETM_API Complex cos(const Complex &complex) {
    return { (std::cos(complex.real) * std::cosh(complex.img)), -(std::sin(complex.real) * std::sinh(complex.img)) };
}

SETM_API Complex sin(const Complex &complex) {
    return { (std::sin(complex.real) * std::cosh(complex.img)), (std::cos(complex.real) * std::sinh(complex.img)) };
}

bool Complex::operator==(const Complex &other) const noexcept {
    constexpr double epsilon{ 2.22e-12L };
    return abs(*this - other) <= epsilon;
}

bool Complex::operator!=(const Complex &other) const noexcept {
    return !(*this == other);
}

bool Complex::operator==(double other) const noexcept {
    return (*this == Complex{ other });
}

bool Complex::operator!=(double other) const noexcept {
    return !(*this == Complex{ other });
}

SETM_API bool operator==(double other, const Complex &complex) noexcept {
    return (complex == other);
}

SETM_API bool operator!=(double other, const Complex &complex) noexcept {
    return !(complex == other);
}

SETM_API std::ostream &operator<<(std::ostream &out, const Complex &complex) {
    out << '(' << complex.real << ", " << complex.img << ')';
    return out;
}

SETM_API std::istream &operator>>(std::istream &in, Complex &complex) {
    in >> complex.real >> complex.img;
    return in;
}

Complex Complex::operator/(const Complex &other) const {
    Complex result{ *this };
    return (result /= other);
}

double Complex::getReal() const noexcept {
    return real;
}

double Complex::getImg() const noexcept {
    return img;
}

Complex Complex::operator*(const Complex &other) const {
    Complex result{ *this };
    return (result *= other);
}

Complex Complex::operator-(const Complex &other) const {
    Complex result{ *this };
    return (result -= other);
}

Complex Complex::operator+(const Complex &other) const {
    Complex result{ *this };
    return (result += other);
}

SETM_API Complex operator+(double value, const Complex &complex) {
    return (complex + value);
}

SETM_API Complex operator-(double value, const Complex &complex) {
    return (Complex{ value } - complex);
}

SETM_API Complex operator*(double value, const Complex &complex) {
    return (complex * value);
}

SETM_API Complex operator/(double value, const Complex &complex) {
    return (Complex{ value } / complex);
}

SETM_API Complex pow(const Complex &complex, double power) {
    const double phi{ std::atan(complex.img / complex.real) };
    const double real{ std::cos(phi * power) };
    const double img{ std::sin(phi * power) };
    const double modulusPower{ std::pow(abs(complex), power) };

    return { modulusPower * real, modulusPower * img };
}

SETM_API Complex nrt(const Complex &complex, double power) {
    return pow(complex, static_cast<double>(1.0 / power));
}

SETM_API double abs(const Complex &complex) {
    return std::sqrt(complex.real * complex.real + complex.img * complex.img);
}

}  // namespace setm
