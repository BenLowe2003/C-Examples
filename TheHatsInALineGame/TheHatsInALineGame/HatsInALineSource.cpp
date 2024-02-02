#include <iostream>
#include <cstdlib>
#include <vector>

bool randhat() {
    return std::rand() % 2 == 0;
}

bool say_output(const std::vector<bool>& heard, const std::vector<bool>& see) {
    int heard_count = 0;
    int see_count = 0;

    for (bool i : heard) {
        if (i) {
            heard_count++;
        }
    }

    for (bool i : see) {
        if (i) {
            see_count++;
        }
    }

    return (heard_count % 2) == (see_count % 2);
}

int compare(const std::vector<bool>& answers, const std::vector<bool>& results) {
    int sum = 0;
    int length = answers.size();
    for (int i = 0; i < length; i++) {
        if ((answers[i] and results[i]) or (not answers[i] and not results[i])) {
            sum++;
        }
    }
    return sum;
}