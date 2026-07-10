#include <iostream>

struct Node{
	int data; 
	Node* prev; 
}; 
class Stack{
private:
	Node* head; 
	int count; 
public: 
	Stack(){
		head = nullptr; 
		count = 0; 
	}
	void push(int d){
		Node* n = new Node; 
		n->data = d; 
		n->prev = head; 
		head = n; 
		count++; 
	}
	void pop(){
		if(!isEmpty()){
			if(count > 1){
				Node *ptr = head->prev; 
				delete head; 
				head = ptr;
				count--; 
			} else {
				delete head; 
				count--;
			}
		}
		
	}
	void top(){
		if(!isEmpty()){
			std::cout << head->data << std::endl; 
		} else std::cout << "-1\n"; 
	}

	bool isEmpty(){
		return (count == 0); 
	}
}; 

int main(){
	int numOfOper; 
	std::cin >> numOfOper; 
	Stack stack; 
	while(numOfOper--){
		int command; 
		std::cin >> command; 
		if(command == 1){
			int tmp; 
			std::cin >> tmp; 
			stack.push(tmp); 
		} else if (command == 2){
			stack.top(); 
		} else if (command == 3){
			stack.pop(); 
		}
	}

	return 0;
}
