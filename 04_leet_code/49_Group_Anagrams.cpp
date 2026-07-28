//I will just write the code in leet code and then paste here instead
//I will include the headers so I know which function belongs to which header. 
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string >> ans;
        std::unordered_map<std::string, std::vector<std::string>> groups; 
        for(int i = 0; i < strs.size(); i++){
            std::string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end()); 
            groups[sorted].push_back(strs[i]); 
        }
        for(const auto& [sorted, group]: groups){
            ans.push_back(group); 
        }
        return ans; 
    }
};
