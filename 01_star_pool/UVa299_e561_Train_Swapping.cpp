#include <iostream>
#include <vector>

void swap(int& a, int& b){
	int temp = a; 
	a = b; 
	b = temp; 
}

int getSwaps(int len, std::vector<int>& carriages){

	int swaps = 0; 
	if(len == 0 || len == 1) return 0; 

	int end_index = len - 1; 

	while(end_index > 0){
		for(int i = 0; i < end_index; i++){
			if(carriages[i] > carriages[i+1]){
				swap(carriages[i], carriages[i+1]); 
				swaps++; 
			}
		}
		end_index--; 
	}
	return swaps; 
}


int main(){
	int num_of_test; 
	std::cin >> num_of_test; 

	while(num_of_test--){
		int len; 
		std::vector<int> carriages; 
		std::cin >> len; 
		for(int i = 0; i < len; i++){
			int temp; 
			std::cin >> temp;
			carriages.push_back(temp); 
		}
		
		int swaps = getSwaps(len, carriages); 
		std::cout << "Optimal train swapping takes " << swaps << " swaps." << std::endl; 
	}

	return 0; 
}
