#include <iostream>
#include <string>
#include <algorithm>
#include <random>

int main()
{
    // This is a random number generator that should be given as parameter to the
    // function of the algorithm library to shuffle letters
    std::minstd_rand generator;

    std::cout << "Enter some text. Quit by entering the word \"END\"." << std::endl;
    std::string word;

    while (std::cin >> word)
    {
        if (word == "END")
        {
            return EXIT_SUCCESS;
        }

        // TODO: implement your solution here
        if (word.size() > 2)
        {
            // Extracting the middle part of the word for shuffling
            std::string middle_part = word.substr(1, word.size() - 2);

            // Shuffle the middle part using std::shuffle
            std::shuffle(middle_part.begin(), middle_part.end(), generator);

            // Reconstruct the shuffled word
            word = word.front() + middle_part + word.back();
        }
        std::cout << word << std::endl;
    }

    return EXIT_SUCCESS;
}
