#include <iostream>

int main() {
    auto *a = new long[4];
    std::cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << std::endl;
    return 0;
}