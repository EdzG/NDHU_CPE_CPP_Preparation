#include <iostream>
#include <string>
#include <cctype>

int value(char c);
int smallesValidFactor(int sum, int max);

int main(){
	std::string input; 
	while(std::cin >> input){
		int sum = 0; 
		int max = 0; 
		for(int i = 0; i < input.length(); i++){
			if(!isalnum(input[i])) continue; 
			int num = value(input[i]);
			sum += num; 
			if(num > max) max = num;
		}
		int N = smallesValidFactor(sum, max) + 1; 
		if(N < 2) std::cout << 2 << "\n"; 
		else if(N <= 62) std::cout << N << "\n";
		else std::cout << "such number is impossible!\n"; 
	}

	return 0; 
}

int value(char c){
	int ans; 
	if(c >= 'A' && c <='Z'){
		return c - 'A' + 10;
	}
	if(c >= 'a' && c <= 'z'){
		return c - 'a' + 26 + 10; 
	}
	return c - '0';
}
int smallesValidFactor(int sum, int max){
	for(int i = 1; i <= sum; i++){
		if(sum % i == 0 && i >= max) {
			return i; 
		}
	}
	return 0; 
}
