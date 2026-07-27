#include <iostream>
#include <vector>

void decToBinary(int input);

int main(){
	int input; 
	while(std::cin >> input){
		decToBinary(input); 
	}

	return 0; 
}

void decToBinary(int input){
	std::vector<int> ans; 
	while(input > 1){
		ans.push_back(input % 2); 
		input /= 2; 
	}
	if(input == 1) ans.push_back(1);
	for(int i = ans.size() - 1; i >= 0; i--){
		std::cout << ans[i]; 
	}
	std::cout << '\n'; 

}
