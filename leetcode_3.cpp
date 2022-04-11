// 3. Longest Substring Without Repeating Characters
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring_2(string s) {
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
    int lengthOfLongestSubstring_1(string s) {
        if(s.length() == 0) return 0;
        else if (s.length() == 1) return 1;
        set<char> _set;

        int n = s.length();
        int i=0, j=0;
        int max_length = 0;
        while(j < n) {
            if (_set.count(s[j]) == 0) {
                // if char not exist in set
                _set.insert(s[j]);
                j++;
                max_length = fmax(max_length, _set.size());
            } else {
                _set.erase(s[i]);
                i++;
            }
        }
        // cout << max_length;

        return max_length;
    }
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        else if (s.length() == 1) return 1;
        int s_length = s.length();

        // fixed length array?
        vector<int> hash(128, 0);

        int max_length = 0;
        int left = 0;
        for(int right = 0; right < s_length; right++) {
            char c = s[right];
            if(hash[c] == 0) {
                // update the max_length
                // use ‘right - left’ is faster than _set.size()
                max_length = fmax(max_length, right - left + 1);
            } else {
                // similar to Solution_1 erase the number from left
                while(hash[c]) {
                    hash[s[left]]--;
                    left++;
                }
            }

            // add current character to hash
            hash[c]++;
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