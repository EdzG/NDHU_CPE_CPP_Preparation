#include <iostream>
#include <iomanip> 
#include <cmath>

int main(){
	int set_of_inputs; 
	std::cin >> set_of_inputs; 
	while(set_of_inputs--){
		int player_count, winning_player; 
		double p; 
		std::cin >> player_count >> p >> winning_player; 
		if(p == 0.0){
			std::cout << "0.0000\n";
			continue; 
		}
		//need to use the infinite geometric series formula
		//sum = a / ( 1 - r) where r is a ratio < 1, 
		// for the player to win on the first run, winning_player - 1 need to lose and the player 
		// needs to win on his first turn. 
		// This is probability * (probability of not winning * winning_player - 1)
		double q = 1 - p; 
		double win_first_round = p * (std::pow(q,(winning_player - 1))); 
		//To win on the second round, everyone needs to lose on the first round
		//and then the condition for win_first_round needs to be met
		// win2 = win1 * q^N -> this pattern repeats, win3 = win1 * q^2n
		double total = win_first_round / (1 - std::pow(q, player_count)); 
		std::cout << std::setprecision(4) << std::fixed << total << "\n"; 
	}

	return 0; 
}
