#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> char_to_int;
        char_to_int['I'] = 1;
        char_to_int['V'] = 5;
        char_to_int['X'] = 10;
        char_to_int['L'] = 50;
        char_to_int['C'] = 100;
        char_to_int['D'] = 500;
        char_to_int['M'] = 1000;
        
        int sum = 0;
        
        for(int index=0; index < s.length(); index++) {
            // if the roman next to it is bigger then
            if(index + 1 < s.length()) {
                if(char_to_int[s[index+1]] > char_to_int[s[index]]){
                    sum -= 2 * char_to_int[s[index]];
                } 
            } 
            sum += char_to_int[s[index]];
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution ans;
    string input;
    while(cin >> input) {
        cout << ans.romanToInt(input) << endl;
    }
    return 0;
}
