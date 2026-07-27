#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target){
		int l = 0, r = nums.size() - 1; 
		std::vector<int> copy = nums; 

		std::sort(copy.begin(), copy.end());
		int first, second; 	
		while(l < r){
			int sum = copy[l] + copy[r]; 
			if(sum == target){
				first = copy[l]; 
				second = copy[r];
				break; 
			}
			if(sum > target) r--; 
			else l++; 
		}
		std::vector<int> ans; 
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] == first || nums[i] == second) ans.push_back(i);
		}
		return ans; 


	}
};
//from leet code
class Solution2{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target){
		std::unordered_map<int, int> numMap; 
		for(int i = 0; i < nums.size(); i++){
			int complement = target - nums[i]; 
			if(numMap.count(complement)){
				return {numMap[complement], i};
			}
			numMap[nums[i]] = i; 
		}
		return {}; 
	}
};
