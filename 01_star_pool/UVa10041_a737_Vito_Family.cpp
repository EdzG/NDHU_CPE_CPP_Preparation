#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int sumOfDistances(const std::vector<int>& data, int index);

int main(){
	int n;
	std::cin >> n;
	while(n--){
		int neighbours;
		std::cin >> neighbours; 
		std::vector<int> vec; 
		vec.reserve(neighbours);
		for(int i = 0; i < neighbours; i++){
			int tmp; 
			std::cin >> tmp; 
			vec.push_back(tmp);
		}
		std::sort(vec.begin(), vec.end()); 
		int index = (vec.size() - 1) / 2;  
		//std::nth_element(vec.begin(), vec.begin() + index, vec.end());
		//The above speeds up O(N log N) to O(N) since it only finds the median
		int sum = sumOfDistances(vec, index);
		std::cout << sum << "\n";
	}
	
	return 0; 
}

int sumOfDistances(const std::vector<int>& data, int index){
	int s = data[index]; 
	int sum = 0; 
	for(int i = 0; i < data.size(); i++){
		// if(i == index) continue; Not needed because s - s = 0
		sum += std::abs(s - data[i]);
	}
	return sum; 
}
