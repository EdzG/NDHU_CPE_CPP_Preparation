#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> unique(nums.begin(), nums.end());
        int length = 0; 
        for (int num : unique) {
            if (unique.find(num - 1) == unique.end()) {
                int cur_num = num;
                int cur_length = 1;

                while(unique.find(cur_num + 1) != unique.end()) {
                    cur_num++;
                    cur_length++;
                }
                length = std::max(length, cur_length);
            }
        }
        return length;
    }
};
