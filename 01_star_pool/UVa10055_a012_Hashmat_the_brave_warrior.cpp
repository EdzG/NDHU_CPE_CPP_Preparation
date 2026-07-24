#include <iostream>
#include <string>
#include <vector>


void printDifference(const std::string& a, std::string b);

int main(){
	//We know opponent > hasmat 
	std::string hasmat, opponent; 
	while(std::cin >> hasmat >> opponent){
		if(hasmat.length() > opponent.length()) printDifference(opponent, hasmat); 
		else if(hasmat.length() == opponent.length()){
			bool isEqual = true; 
			for(int i = 0; i < hasmat.length(); i++){
				if(hasmat[i] == opponent[i]) continue; 
				if(hasmat[i] < opponent[i]) {
					printDifference(hasmat, opponent); 
					isEqual = false; 
					break; 
				}
				else {
					printDifference(opponent, hasmat); 
					isEqual = false; 
					break; 
				}
			}

			if(isEqual) std::cout << "0\n"; 

		} else printDifference(hasmat, opponent); 
	}
	return 0; 
}

void printDifference(const std::string& a, std::string b){
	//since b > a, then length(a) <= length(b); 
	std::vector<int> result; 
	int j = a.length() - 1; 
	int borrow; 
	for(int i = b.length() - 1; i >= 0; i--){
		int cur = j; 
		j--;
		if(cur >= 0) {
			if(b[i] < a[cur]){ //need to borrow; 
				int index = i - 1;
				while(true){
					if(index == -1) break; 
					if(b[index] != '0'){ //no need to continue borrowing, subtract 1
						b[index] = char(b[index] - 1); //borrowing complete
						// std::cout << "B[index]: " << b[index] << "\n"; 
						int updated_original = b[i] - '0';
						updated_original += 10; 
						result.push_back(updated_original - (a[cur] - '0')); //succesfuly borrow. 
						break; 
					} else { 
						b[index] = 9 + '0';  // change it 9 because need to borrow from ahead. 
					}
					index--; 

				}


			} else{ //no need to borrow, >=
				int num = b[i] - a[cur]; 
				result.push_back(num);
			}
		} else {
			result.push_back(b[i] - '0');
		}
	}
	bool isLeadingZero = true;
	int index = result.size() - 1; 
	if(index == 0 && result[index] == 0) std::cout << "0";

	for(int i = index; i >= 0; i--){
		if(isLeadingZero && result[i] == 0) continue; 
		isLeadingZero = false; 
		std::cout << result[i]; 
	}
	std::cout << "\n"; 
}
