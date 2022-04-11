// 3. Longest Substring Without Repeating Characters
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int max_length = 1;
        map<char,int> char_index_map;
        char_index_map[s[0]] = 0;

        int index=1;
        int length = 1;
        for(index=1; index < s.length(); index++) {
            
            if(char_index_map.find(s[index]) != char_index_map.end()) {
                // if current char is same as previous char
                
                // cout << "find same char-index: " << index << ":" << s[index] << " " << length << endl;
                if(length > max_length) {
                    max_length = length;
                } 
                // set index to the former character's index
                index = char_index_map[s[index]];
                // clear map
                char_index_map.clear(); 
                length = 0;
            } else {
                length += 1;
                if(length > max_length) {
                    max_length = length;
                } 
                // cout << "index: " << index << ":" << s[index] << " " << length << endl;
                char_index_map[s[index]] = index;
            }

        }
        // cout << max_length;

        return max_length;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string str = "pwawkew";

    solution.lengthOfLongestSubstring(str);
    return 0;
}