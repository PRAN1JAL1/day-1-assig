/*Check if a Number is Prime
Objective
Check if a given number n is a prime number. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
 To determine if a number is prime, iterate from 2 to √n and check if n is divisible by any number in this range. If it is divisible, it is not a prime number; otherwise, it is a prime.*/
#include <iostream>
#include <cmath> // for sqrt function

bool isPrime(int n) {
    if (n <= 1) return false; // Numbers <= 1 are not prime
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false; // If divisible, not prime
    }
    return true; // Prime if no divisors were found
}

int main() {
    int n;

    std::cout << "Enter a number to check if it's prime: ";
    std::cin >> n;

    if (isPrime(n)) {
        std::cout << n << " is a prime number.\n";
    } else {
        std::cout << n << " is not a prime number.\n";
    }

    return 0;
}
