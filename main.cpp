#include <iostream>
#include "Set.h"

int main() {
    srand(time(nullptr));
    Set s1 = Set(3);
    Set s2 = Set(2);
    cout << "A = " << s1 << endl;
    cout << "B = " << s2 << endl;
    Set s3 = s1 + s2;
    cout << "A + B = " << s3 << endl;
    Set s4 = s1 - s2;
    cout << "A - B = " << s4 << endl;
    Set s5 = s2 - s1;
    cout << "B - A = " << s5 << endl;
    Set s6 = s1 * s2;
    cout << "A * B = " << s6 << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

