#include <iostream>
#include <string>

int main(){
	std::string input; 
	std::cin >> input; 
	int r = input.length() - 1, l = 0; 
	while(l <= r){
		if(input[l] != input[r]){
			std::cout << "no" << std::endl; 
			return 0; 
		}
		l++; 
		r--; 
	}
	std::cout << "yes" << std::endl; 
	

	return 0; 
}
