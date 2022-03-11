#include <iostream>
#include <cmath>
// #include <xtensor/xarray.hpp>
// #include <xtensor/xio.hpp>
// #include <xtensor/xview.hpp>

int main() {
    std::cout << "2+3x4=" << (2+3*4) << std::endl;
    std::cout << "(2+3)x4=" << (2+3)*4 << "\n";
    std::cout << "2^10=" << std::pow(2, 10) << std::endl;
    std::cout << "6./3=" <<float(6)/3 << std::endl;
    std::cout << "6/5=" << 6/5 << std::endl;
    std::cout << "15mod4=" << 15%4 << "\n";
    std::cout << "6^15=" << std::pow(6, 15) << std::endl;
    return 0;
}