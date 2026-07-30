#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

int main(){
	std::string line; 
	while(std::getline(std::cin, line)){
		std::unordered_map<char, int> freq; 
		for(auto& c: line){
			if(c == '\n' || c == '\r') continue; 
			freq[c]++; 
		}
		std::vector<std::pair<char, int>> sorted(freq.begin(), freq.end()); 
		std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b){
			if(a.second != b.second) return a.second < b.second;
			else return a.first > b.first; 
		});
		for(const auto& [chr, count]: sorted){
			std::cout << static_cast<int>(chr) << " " << count << "\n"; 
		}
		std::cout << "\n"; 
	}	

	return 0; 
}
