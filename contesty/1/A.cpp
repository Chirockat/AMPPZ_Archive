// Generalnie musi to być parzysta liczba większa niż 2, tyle

#include<iostream>

int main() {
    int number;

    std::cin >> number;

    if(number > 2 && number % 2 == 0) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

}