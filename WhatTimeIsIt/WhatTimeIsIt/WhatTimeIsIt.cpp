// WhatTimeIsIt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

int main() {
	std::cout << "What time is it: ";
	time_t current_time = time(0);
	std::cout << current_time << "\n";
	int years = (current_time / (60 * 60 * 24 * 365));
	int days = (current_time / (60 * 60 * 24 ));
	int months = (days - years * 365) / 30;
	std::cout << "Or " << years << " years and " << months << " months.";
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
