#include <iostream>
#include <vector>
#include <algorithm> //sorting, swap, max, min, count
#include <string>
#include <cctype> //tolower, toupper, isdigit, isalpha

int main(){
	int n; 
	char c; 
	std::vector<int> freq(26, 0);

	std::cin >> n; 
	while(std::cin.get(c)){
		if(!std::isalpha(c)) continue; 
		c = std::tolower(c);
		// std::cout << "char: " << c << std::endl;
		freq[c - 'a'] += 1;
	}
	// for(int i = 0; i < freq.size(); i++){
	// 	std::cout << freq[i] << " " << static_cast<char>(i + 'a')<< '\n'; 
	// }

	std::vector<std::pair<int, char>> result;
	for(int i = 0; i < freq.size(); i++){
		if(freq[i] != 0){
			result.push_back(std::make_pair(freq[i], static_cast<char>(i + 'a')));
		}
	}
	std::sort(result.begin(), result.end(), [](const auto& a, const auto& b){
		if(a.first != b.first){
			return a.first > b.first;
		} 
		return a.second < b.second;
	});

	for(const auto& pair: result){
		char chr = std::toupper(pair.second);
		std::cout << chr << " " << pair.first << "\n";
	}
	return 0;
}
