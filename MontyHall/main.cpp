// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LetsMakeADeal.h"
#include <iostream>

void helper() {

	std::cout << "How to play" << std::endl << std::endl;
	std::cout << "First argument: \"switch\" or \"stay\" " << std::endl;
	std::cout << "Second argument: Enter the number of game instances" << std::endl;
	std::cout << "Third argument: Enter the number of doors (Note: must be greater than 2)" << std::endl;
	std::cout << "Third argument: Enter the number of doors to be revealed (Note: must be at least 2 less than number of doors)" << std::endl << std::endl;
	std::cout << "Example: switch 10 3 1" << std::endl;
	std::cout << "This will run 10 instances of the game with 3 doors and 1 revealed door with a decision to switch doors." << std::endl;
	
	// exits program
	exit(EXIT_FAILURE);
}

int check_switch(const std::string switch_or_stay) {
	
	// 1 for switch; 2 for stay
	auto decide_switch_or_stay{ 0 };

	// decide to switch
	if (switch_or_stay == "switch") {
		decide_switch_or_stay = 1;
	}
	// decide to stay
	else if (switch_or_stay == "stay") {
		decide_switch_or_stay = 2;
	}
	// handle invalid command line argument
	else {
		helper();
	}

	return decide_switch_or_stay;
}

int verify_num_doors(const int argc, char* argv[]) {

	// default doors to 3
	auto number_doors = 3;

	if (argc > 3) {
		// assign command line arguments to integer
		number_doors = std::atoi(argv[3]);
	}

	// make sure that a minimum number of 3 doors is chosen
	if (number_doors <3) {
		helper();
	}

	return number_doors;
}

int verify_reveal_doors(const int argc, char* argv[], const int number_doors) {

	auto reveal_number_doors = 1;
	if (argc > 4) {
		reveal_number_doors = std::atoi(argv[4]);
	}

	// make sure the # of revealed doors is at least 2 less than the number of doors
	if (reveal_number_doors > (number_doors -2)) {
		helper();
	}

	return reveal_number_doors;
}

void start_game(const int argc, char* argv[]) {

	// verify and assign command line arguments 
	const auto to_switch_or_not{ check_switch(argv[1]) };
	const auto number_games { std::atoi(argv[2]) };
	const auto number_doors{ verify_num_doors(argc, argv) };
	const auto reveal_number_doors{ verify_reveal_doors(argc, argv, number_doors) };

	// start the game
	LetsMakeADeal play_game(to_switch_or_not, number_games, number_doors, reveal_number_doors);
}

int main(const int argc, char* argv[]) {
	
	start_game(argc, argv);

	return 0;
}