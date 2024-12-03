#include <iostream>

#include <mauri/math/Range.hpp>

using mauri::Range;

int main (int argc, char *argv[]) {
    for (int i : Range(10, 20, 3)) {
        std::cout << i << std::endl;
    }
    return 0;
}
