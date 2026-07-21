#include <iostream>
#include <string>

int numOfCarry(std::string a, std::string b);

int main(){
	std::string a, b; 

	while(std::cin >> a >> b){
		if((a == "0") && (b == "0")) break; 
		int num = numOfCarry(a, b); 
		if(num > 1){
			std::cout << num << " carry operations.\n";
		} else if(num == 1) std::cout << "1 carry operation.\n";
		else std::cout << "No carry operation.\n";
	}
	return 0; 
}
int numOfCarry(std::string a, std::string b){
	int count = 0, carry = 0; 
	int index_a = a.length() - 1, index_b = b.length() - 1; 

	while(index_a >= 0 || index_b >= 0 || carry > 0){
		int num = 0, num2 = 0;

		if(index_a >= 0){
			num = static_cast<int>(a[index_a] - '0'); 
			index_a--; 
		}
		if(index_b >= 0){
			num2 = static_cast<int>(b[index_b] - '0');
			index_b--; 
		}
		int add = num + num2 + carry; 
		if(add > 9) count++; 
		carry = add / 10;
	}

	return count; 
}
