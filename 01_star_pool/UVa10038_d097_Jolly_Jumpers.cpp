#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
	int n; 
	while(std::cin >> n){
		std::vector<int> seq; 
      		int tmp; 
      		std::cin >> tmp; 
		for(int i = 1; i < n; i++){
			int num; 
			std::cin >> num; 
			seq.push_back(std::abs(num - tmp)); 
			tmp = num; 
		}
		std::sort(seq.begin(), seq.end()); 
		// for(const auto& i: seq){
		// 	std::cout << i << " "; 
		// }
		bool isJolly = true; 
		for(int i = 0; i < seq.size(); i++){
			if(seq[i] != i + 1){
				isJolly = false; 
				break;  
			}
		}
		if(isJolly) std::cout << "Jolly\n";
		else std::cout << "Not jolly\n";

	}
	return 0; 
}
