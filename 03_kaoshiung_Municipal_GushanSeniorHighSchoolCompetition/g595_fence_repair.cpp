#include <iostream>
#include <vector>

int main(){
	int n; 
	std::cin >> n; 
	std::vector<int> input; 
	for(int i = 0; i < n; i++){
		int tmp; 
		std::cin >> tmp; 
		input.push_back(tmp); 
	}

	int ans = 0;  
	for(int i = 0; i < input.size(); i++){
		if(input[i] != 0) continue; 
		//starting fence is 0
		if(input[i] == 0 && i == 0){
			ans += input[i+1]; 
		} else if(input[i] == 0 && i == input.size() - 1){ //ending fence is 0; 
			ans += input[i-1]; 
		} else {
			if(input[i - 1] < input[i+1]){
				ans += input[i-1]; 
			} else ans += input[i+1]; 
		}

	}
	std::cout << ans << std::endl; 

	return 0; 
}
