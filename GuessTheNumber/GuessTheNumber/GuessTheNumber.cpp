// GuessTheNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    srand(time(0));
    std::cout << "Guess The Number. \n";
    const int num_array[] = { 1,2,3, 4, 5, 6, 7, 8, 9 };

    int rand_index = rand() % (sizeof(num_array) / sizeof(num_array[0]));
    int player_guess;
    std::cout << "What number do you guess: ";
    std::cin >> player_guess;


    int bot_guess = num_array[rand_index];

    std::cout << "the random number is " << bot_guess << endl;

    if (player_guess == bot_guess) {
        std::cout << "You Win!!! \n";
    }
    else {
        std::cout << "You Loose \n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
