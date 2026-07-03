#include <iostream>

int cycle_length(int n){
	int count = 1; 
	while(true){
		if (n == 1) break; 
		if (n % 2 == 1) n = 3*n + 1; 
		else n = n/2;
		count++; 
	}
	return count; 
}
int main(){
	int i, j; 
	while(std::cin >> i >> j){
	int max=1; 

	//Print the input in the same order; 
	std::cout << i << " " << j << " "; 

	//let i < j; 
	if (j < i){
		int temp = i; 
		i = j; 
		j = temp; 
	}

	for (; i <= j; i++){
		int cycle_len = cycle_length(i);
		if (cycle_len > max) max = cycle_len; 
	}
	std::cout << max << std::endl; 
	}
	return 0; 
}
