#include <vector>
#include <unordered_map>
#include <algorithm>


class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq; 
        std::vector<int> ans; 
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++; 
        }
        std::vector<std::pair<int, int>> sorted(freq.begin(), freq.end());
        std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b){
            return a.second > b.second; 
        }); 

        int i = 0; 
        for(const auto& [num, count]: sorted){
            if(i == k) break; 
            ans.push_back(num); 
            i++; 
        }
        return ans; 
    }
};
