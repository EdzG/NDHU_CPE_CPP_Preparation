#include <iostream>
#include <vector>


int working_days_lost(std::vector<std::pair<int, int>>& unique, int days);

int main(){
	int test_cases; 
	std::cin >> test_cases; 
	while(test_cases--){
		int days, parties;
		std::vector<int> hartals(3651, 0); 
		std::cin >> days >> parties; 
		for(int i = 0; i < parties; i++){
			int tmp; 
			std::cin >> tmp;
			hartals[tmp] = 1; 
		}
		std::vector<std::pair<int, int>> hartals_k; //<hartal_parameter, k> where k is the counter 1 - k; 
		for(int i = 0; i < hartals.size(); i++){
			if(hartals[i] != 0){
				hartals_k.push_back(std::make_pair(i, 1)); 
			}
		}
		// for(const auto& i: hartals_k){
		// 	std::cout << i.first << " " << i.second << "\n"; 
		// }
		std::cout << working_days_lost(hartals_k, days) << "\n"; 

	}

	return 0; 
}

int working_days_lost(std::vector<std::pair<int, int>>& unique, int days){
	int days_lost = 0; 
	int day = 1; //1 = Sunday, 7 = Saturday
	int total_days = 1; 
	bool isHartal = false; 
	for(int i = 0; i < days; i++){
		for(int i = 0; i < unique.size(); i++){
			if(!isHartal && day != 6 && day != 7 && unique[i].first == unique[i].second) isHartal = true; 
			unique[i].second = unique[i].second % unique[i].first + 1; //avoids the remainder of 0, starts with 1
			// std::cout << unique[i].first <<  " " << unique[i].second << "\n"; 
		}
		// std::cout << "\n";
		if(isHartal) days_lost += 1; 
		isHartal = false; 
		day = day % 7 + 1; 
		total_days += 1; 
		// std::cout << "Day: " << day << " Total days: " << total_days << "\n"; 
	}
	return days_lost; 
}
