#include <iostream>
// #include <string>
#include <vector>


void print(const std::vector<std::vector<char>>& input, int maxLen);

int main() {
  std::vector<std::vector<char>> input;
  std::vector<char> currentRow;
  char c;
  int numOfSentences = 0, maxLen = 0; 

  while (std::cin.get(c)) {

    if (c == '\n') {
	//if last input is \n it doesn't push an emptyrow
	input.push_back(currentRow);
	if(currentRow.size() > maxLen) maxLen = currentRow.size(); 
	currentRow.clear();
    } else currentRow.push_back(c);
	
  }
  // Incase the last line doesn't have \n;
  if (!currentRow.empty()) {
	input.push_back(currentRow);
	if(currentRow.size() > maxLen) maxLen = currentRow.size(); 
  }
	//
	//  for (const auto &row : input) {
	//    for (char chr : row) {
	//      std::cout << chr;
	//    }
	//  }
	// std::cout << std::endl; 
	print(input, maxLen); 

  return 0;
}

void print(const std::vector<std::vector<char>>& input, int maxLen){

	for(int i = 0; i < maxLen; i++){
		for(int j = input.size() - 1; j >= 0; j--){
			if(i < input[j].size()){ std::cout << input[j][i]; }
			else std::cout << ' '; 
		}
		std::cout << '\n'; 
	}
}
