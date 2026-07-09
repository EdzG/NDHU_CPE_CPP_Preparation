#include <iostream>
#include <vector>
//Forcing myself to learn the headers
// #include <algorithm> //sorting, swap, max, min, count
// #include <string>
// #include <cctype> //single character modifications tolower, toupper, isDigit, isAlpha. 
// #include <cmath>

void findSubset(const std::vector<int> fib, int num); 

int main(){
	std::vector<int> input; 
	std::vector<int> fib{0, 1};  
	int max = 46; 
	fib.resize(max);	
	for(int i = 2; i < max; i++){
		fib[i] = fib[i-1] + fib[i-2]; 
	}

	int numOfInput; 

	std::cin >> numOfInput; 
	for(int i = 0; i < numOfInput; i++){
		int tmp; 
		std::cin >> tmp; 
		std::cout << tmp << " = ";
		findSubset(fib, tmp); 
		std::cout << " (fib)\n"; 
	}
	return 0; 
}

void findSubset(const std::vector<int> fib, int num) {
	std::vector<int> ans; 
	int balance = num;
	for(int i = fib.size() - 1; i > 1; i--){
		if(fib[i] > num) continue; 
		if(balance - fib[i] >= 0){
			ans.push_back(1); 
			balance -= fib[i]; 
		} else {
			ans.push_back(0); 
		}
	}
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i]; 
	}
}
