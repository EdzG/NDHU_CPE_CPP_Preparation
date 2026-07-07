#include <iostream>
#include <string>

int main(){

	std::string line; 

	int orientation = 0; 
	char c; 

	while(std::cin.get(c)){
		// if(c == '\r') continue; 
		if(c == '\"'){
			if(orientation % 2 == 0) {
				std::cout << "``"; 
			} else std::cout << "''"; 
			orientation++; 
		} else {
			std::cout << c; 
		}
	}

	return 0; 
}
