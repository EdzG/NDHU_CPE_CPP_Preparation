#include <string>
#include <vector>
#include <cctype>

class Solution{
public:
	bool isAnagram(std::string s, std::string t){
		if(s.length() != t.length()) return false; 
		std::vector<int> contains(26, 0);
		for(int i = 0; i < s.length(); i++){
			int index = tolower(s[i]) - 'a'; 
			contains[index]++; 
			index = tolower(t[i] - 'a');
			contains[index]--; 
		}
		for(int i = 0; i < contains.size(); i++){
			if(contains[i] != 0) return false; 
		}
		return true; 

	}
};
