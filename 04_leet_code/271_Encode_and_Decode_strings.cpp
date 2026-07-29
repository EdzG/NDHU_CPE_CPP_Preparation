#include <vector>
#include <string>

//This was solved on NeetCode because on leetcode it is locked behind a paywall. 
class Solution {
public:

	std::string encode(std::vector<std::string>& strs) {
        std::string joined = ""; 
        for(int i = 0; i < strs.size(); i++){
            std::string str = std::to_string(strs[i].length()) + "*" + strs[i];
            joined += str; 
        }
        return joined; 
    }

	std::vector<std::string> decode(std::string s) {
       std::vector<std::string> ans; 
       int index = 0;  
       int num = 0; 
       while(index < s.length()){
        char c = s[index]; 
        if(c != '*'){
            num = num * 10 + (c - '0'); 
            index++; 
        } else {
            std::string str = "";
            index = index + 1; //ignore *
            for(int i = 0; i < num; i++){
                str += s[index]; 
                index++; 
            }
            ans.push_back(str); 
            num = 0; 
        }
       }
        return ans; 
    }
};
