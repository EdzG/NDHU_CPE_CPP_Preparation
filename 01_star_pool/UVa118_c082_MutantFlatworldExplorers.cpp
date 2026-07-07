#include <iostream>
#include <vector>
#include <string>

//N, E, S, W 
static char direction[] = {'N', 'E', 'S', 'W'}; 

class Grid{
private:
	int rows, cols; 
	std::vector<int> grid;  
public: 
	Grid(int h, int w) : rows(h), cols(w){
		//2d vector intialized to all zeros
		grid.resize(rows * cols, 0); 
	}

	int& at(int x, int y) {
		return grid[y * cols + x]; 
	}

	int get(int x, int y) const {
		return grid[y * cols + x]; 
	}

	bool outOfBoundary(int x, int y){
		if(x >= cols || x < 0) return 1; 
		if(y >= rows || y < 0) return 1; 
		return 0; 
	}
	bool scented(int x, int y){
		return get(x, y); 
	}
	void addScent(int x, int y){
		at(x, y) = 1; 
	}

	

};

class Robot{
private: 
	int x, y, d; 
	Grid& flatWorld; 
public: 
	Robot(int x, int y, char a, Grid& grid) : x(x), y(y), flatWorld(grid){
		if(a == 'N') d = 0; 
		if(a == 'E') d = 1; 
		if(a == 'S') d = 2; 
		if(a == 'W') d = 3;
	}

	int getD() {return d;}
	int getY() {return y;} 
	int getX() {return x;}

	void updateD(char a){
		// std::cout << "starting direction: " << direction[d] << std::endl; 
		if(a == 'R'){
			d = (d + 1) % 4; 
		} else if (a == 'L'){
			if (d - 1 < 0 ) d = 3;
			else d -= 1; 
		}

		// std::cout << "direction after update: "<< direction[d] << std::endl; 

	}
	//In the future use moveFoward as the bool
	bool moveForward(){
		// std::cout << "Before moving Forward: X: " << x << " Y: " << y << std::endl; 
		int nextX = x; 
		int nextY = y; 
		if(d == 0) nextY++; 
		if(d == 1) nextX++; 
		if(d == 2) nextY--; 
		if(d == 3) nextX--; 
		//moves forward normally
		if(!flatWorld.outOfBoundary(nextX, nextY)){
			x = nextX; 
			y = nextY; 
			return 0; 
		} else if(!flatWorld.scented(x, y)){ //dies if not scented
			flatWorld.addScent(x, y); 
			return 1; 
		} // else cannot die because it is scented...do nothing
		
		// std::cout << "After moving forward: X: " << x << " Y: " << y << std::endl; 
		
		return 0; 
	}

	void print(bool status){
	//if status is true, robot lost

		// std::cout << "***********************************" << std::endl; 
		if(status) {
			std::cout << x << " " << y << " " << direction[d] << " LOST" << std::endl;
		} else std::cout << x << " " << y << " " << direction[d] << std::endl; 
		
		// std::cout << "***********************************" << std::endl; 
	}

};

int main(){
	int rows, cols, x, y;
	char d; 
	//end coordinates of the grid
	std::cin >> cols >> rows; 

	int height = rows + 1; 
	int width = cols + 1; 
	
	Grid grid(height, width); 

	while(std::cin >> x >> y >> d){
		Robot r(x, y, d, grid);
		bool status = 0; 
		std::cin.ignore(); 

		std::string commands; 
		std::getline(std::cin, commands); 

		// std::cout << "command: " << commands << std::endl; 

		for(char c : commands){
			// std::cout << "character: " << c << std::endl; 
			if(c == 'F') { status = r.moveForward(); }
			else {r.updateD(c); }
			if(status) break; 
		}
		
		r.print(status); 
	}

	return 0;
}
