#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

bool randhat() {
    return std::rand() % 2 == 0;
}

bool say_output(const std::vector<bool>& heard, const std::vector<bool>& see) {
    int count = 0;

    for (bool i : heard) {
        if (i) {
            count++;
        }
    }

    for (bool i : see) {
        if (i) {
            count++;
        }
    }

    return (count % 2) == 0;
}

int compare(const std::vector<bool>& answers, const std::vector<bool>& results) {
    int sum = 0;
    int length = answers.size();
    for (int i = 0; i < length; i++) {
        if ((answers[i] and not results[i]) or (not answers[i] and results[i])) {
            sum++;
        }
    }
    return sum;
}

int print(const std::vector<bool>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

bool random_hats(const int n) {



    std::vector<bool> hats(n);
    std::vector<bool> say(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hats[i] = randhat();
        }
    }

    for (int i = 0; i < n; i++) {
        std::vector<bool> heard(i);
        std::vector<bool> see(n - i - 1);

        for (int j = 0; j < i; j++) {
            heard[j] = say[j];
        }

        for (int j = 0; j < n - i - 1; j++) {
            see[j] = hats[j + i + 1];
        }

        bool color = say_output(heard, see);
        say[i] = color;
    }

    //std::cout << "Hat colour: ";
    //print(hats);
    //std::cout << "Hat guess:  ";
    //print(say);


    int mistakes = compare(say, hats);

    return mistakes == 0;
}