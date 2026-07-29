#include <vector>
class Solution {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> ans; 
        for(int i = 0; i < nums.size(); i++){
            int tmp = 1; 
            if(i != nums.size() - 1){
                for(int j = i + 1; j < nums.size(); j++){
                    tmp *= nums[j]; 
                }
            }
            if(i != 0){
                for(int z = i - 1; z >=0; z--){
                    tmp *= nums[z];
                }
            }
            ans.push_back(tmp); 
        }
        return ans; 
    }
};


