// Copyright 2022 Anson Cheang, and Andy Nguyen
#include <iostream>
#include <SFML/System.hpp>
#include "EDistance.h"

using namespace std; //NOLINT

int main(int argc, const char* argv[]) {
    sf::Clock clock;
    sf::Time t;

    string input1, input2;
    cin >> input1;
    cin >> input2;
    EDistance dna(input1, input2);
    int distance = dna.optDistance();
    cout << "Edit Distance = " << distance << endl;
    cout << dna.alignment();

    t = clock.getElapsedTime();
    // cout << "Edit Distance = " << distance << endl;
    cout << "Execution time is " << t.asSeconds() << " seconds \n";
}
