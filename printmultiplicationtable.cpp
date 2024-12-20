/*2. Print Multiplication Table of a Number
Objective
Print the multiplication table of a given number n. A multiplication table for a number n is a list of products of n with integers from 1 to 10. For example, the multiplication table for 3 is:
3×1=3,3×2=6,…,3×10=30.*/
)#include <iostream>

int main() {
    int n;

    std::cout << "Enter a number to print its multiplication table: ";
    std::cin >> n;

    std::cout << "Multiplication Table for " << n << ":\n";
    for (int i = 1; i <= 10; ++i) {
        std::cout << n << " × " << i << " = " << n * i << "\n";
    }

    return 0;
}
