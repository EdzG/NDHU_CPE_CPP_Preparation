#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int n; 
	while(std::cin >> n){

		std::vector<int> input(n, 0); 
		for(int i = 0; i < n; i++){
			int tmp; 
			std::cin >> tmp;
			input[i] = tmp; 	
		}
		std::sort(input.begin(), input.end());
		int lower_median = input[(n-1)/2]; 
		int upper_median = input[n/2]; 

		int count = 0; 
		for(int i = 0; i < input.size(); i++){
			if(input[i] >= lower_median && input[i] <= upper_median){
				count++; 
			}
		}

		int unique = upper_median - lower_median + 1; 
		std::cout << lower_median << " " << count << " " << unique << "\n"; 
	}
	return 0; 
}
