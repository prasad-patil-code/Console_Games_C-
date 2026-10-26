//main.cpp
#include "random.h"
#include <iostream>



void gamelogic()
{
	std::cout << "Let's play a game. I am thinking of a integer between 1 and 100. You have to guess what it is in just seven chances. \n";

	int num{Random::get(1,100)};

	int guess{};


	for(int i{1}; i <= 7; ++i)
	{
		std::cout << "Guess #" << i << " :";
		std::cin >> guess;

		if(guess > num)
			std::cout << "Your guess is too high \n";

		else if(guess < num)
			std::cout << "Your guess is too low \n";

		else
		{
			std::cout << "Congratulations!! Correct guess. You won... :) \n";
			break;
		}
	}

	if(guess != num)
		std::cout << "Sorry, you lose. The number is " << num << "\n";


	return;
}


bool input()
{
	char tell{};

	std::cout << "Do you wanna try again ? (y/n) : ";
	std::cin >> tell;

	if(tell == 'y' || tell == 'Y')
		return true;
	else
		return false;

}


int main()
{


	do
	{
		gamelogic();
	}
	while(input());

	std::cout << "Thanks for Playing. \n";

	return 0;
}



//random.h
#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

namespace Random
{
    // Returns a seeded Mersenne Twister
    inline std::mt19937 generate()
    {
        std::random_device rd{};

        // Create seed_seq with clock and 7 random numbers from std::random_device
        std::seed_seq ss{
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
            rd(), rd(), rd(), rd(), rd(), rd(), rd()
        };

        return std::mt19937{ ss };
    }

    // The inline keyword ensures we only have one global instance for our whole program
    inline std::mt19937 mt{ generate() };

    // Generate a random int between min and max (inclusive)
    inline int get(int min, int max)
    {
        std::uniform_int_distribution distribution{ min, max };
        return distribution(mt);
    }
}

#endif
