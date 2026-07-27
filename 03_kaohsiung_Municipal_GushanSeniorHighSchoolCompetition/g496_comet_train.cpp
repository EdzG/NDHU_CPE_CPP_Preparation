#include <iostream>
#include <cmath>

int main(){
	int acceleration, target; 
	std::cin >> acceleration >> target; 
	std::cout << (target + acceleration - 1) / acceleration << std::endl; 
	

	return 0; 
}
