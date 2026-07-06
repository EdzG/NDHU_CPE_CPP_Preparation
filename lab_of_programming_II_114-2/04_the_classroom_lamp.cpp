#include <iostream>

class Lamp{
private:
	bool state; 
public:
	Lamp():state(0){}
	void toggle() {state = !state; }
	void print(){
		if(state) std::cout << "ON" << std::endl; 
		else std::cout << "OFF" << std::endl; 
	}
}; 
int main(){

	int numOfOper;
	std::cin >> numOfOper; 
	Lamp lamp; 
	while(numOfOper--){
		std::string command; 
		std::cin >> command; 
		if(command == "toggle")
			lamp.toggle(); 
	}
	lamp.print(); 
	// std::cout << ((numOfOper % 2)? "ON" : "OFF")<< std::endl; 
	return 0; 
}
