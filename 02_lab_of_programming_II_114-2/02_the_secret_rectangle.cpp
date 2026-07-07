#include <iostream>

class Rectangle{
private:
	int height, width; 
public:
	Rectangle(int h, int w):height(h), width(w){}
	int area(){
		return height * width; 
	}
	void printArea(){
		std::cout << "Area: " << area() << std::endl; 
	}
};
int main(){
	int h, w; 
	std::cin >> w >> h; 

	Rectangle obj(h, w); 
	obj.printArea(); 

	return 0; 
}
