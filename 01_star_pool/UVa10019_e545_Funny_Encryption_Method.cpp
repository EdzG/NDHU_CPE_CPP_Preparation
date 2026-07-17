#include <iostream>
// #include <vector>
// #include <algorithm> //sorting, swap, max, min, count
#include <cctype> //tolower, toupper, isdigit, isalpha

// 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001
// 1010, 1011, 1100, 1101, 1110, 1111
//Assume we will only receive digits so we need 0 ~ 9
static int onesInHexToBinary[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2};

int onesInBinary(int decimal);
int onesInHexa(int hexadecimal);

int main(){
	int n; 
	std::cin >> n;
	while(n--){
		int num; 
		std::cin >> num; 
		std::cout << onesInBinary(num) << " " << onesInHexa(num) << "\n"; 
	}

	return 0; 
}

int onesInBinary(int decimal){
	int b1 = 0;
	while(decimal > 0){
		if((decimal % 2) == 1) b1+=1; 
		decimal /= 2; 
	}
	return b1; 
}
int onesInHexa(int hexadecimal){
	// 0000, 0001, 0010, 0011, 0100, 
	int b2 = 0; 
	while(hexadecimal > 0){
		b2 += onesInHexToBinary[hexadecimal % 10];
		hexadecimal /= 10; 
	}
	return b2; 
}
