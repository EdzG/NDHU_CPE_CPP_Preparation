#include <iostream>
#include <string>

class Student{
private:
	std::string name, std_id;
	int age; 

public:
	Student(std::string name, std::string id, int age): name(name), std_id(id), age(age) {}
	void print(){
		std::cout << "Name: " << name << std::endl;
		std::cout << "ID: " << std_id << std::endl; 
		std::cout << "Age: " << age << std::endl; 
	}

};
int main(){
	std::string name, id; 
	int age; 
	std::cin >> name >> id >> age; 
	Student std(name, id, age); 
	std.print(); 
	return 0; 
}
