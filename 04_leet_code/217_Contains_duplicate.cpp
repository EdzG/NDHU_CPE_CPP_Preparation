#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution{
public: 
	bool containsDuplicate(std::vector<int>& nums){
		std::sort(nums.begin(), nums.end());
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] == nums[i-1]) return true; 
		}
		return false; 
	}

};
//Solution from leet code, typing it so I can learn the syntax. 

class Solution2{
public: 
	bool containsDuplicate(std::vector<int>& nums){
		std::unordered_map<int, int> seen; 
		for(int num: nums){
			if(seen[num] >= 1) return true; 
			seen[num]++;
		}
		return false; 
	}

};
