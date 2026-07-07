#include <iostream>
#include <cctype>

class BankAccount{
private:
	int balance; 
public: 
	BankAccount(int b = 0) : balance(b){}
	void deposit(int d) {
		balance += d; 
	}
	void withdraw(int w){
		balance -= w; 
		//As this is a simple program I am not validating the inputs
	}
	void print(){
		std::cout << "Balance: " << balance << std::endl; 
	}

};
int main(){

	int numOfOper, initial_balance; 
	std::cin >> initial_balance >> numOfOper; 
	BankAccount obj(initial_balance); 
	while (numOfOper--){
		std::string command; 
		int amount; 
		std::cin >> command >> amount; 
		if(command == "deposit"){obj.deposit(amount);}
		else if (command == "withdraw") {obj.withdraw(amount);}
		else std::cout << "Invalid command" << std::endl; 

	}
	obj.print(); 

	return 0; 
}
