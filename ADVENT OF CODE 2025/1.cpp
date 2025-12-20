#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#define print(var) cout << #var << ": " << var << endl;

int main()
{
    int main_value = 50;
    int zero_counter = 0;

    string input;

    while (getline(cin, input))
    {

        char direction = input[0];
        int number = stoi(input.substr(1));

        if(number > 99) {
            number = number % 100;
        }

        if (direction == 'L')
        {
            main_value -= number;
            if (main_value < 0)
            {
                main_value = 100 + main_value;
            }
        }
        else
        {
            main_value += number;
            if (main_value > 99)
            {
                main_value -= 100;
            }
        }
        
        if(main_value == 0) {
            zero_counter++;
            
        }
        print(main_value);
        print(zero_counter);
    }
    
}