#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> index_map;
        int diff = 0;
        vector<int> ans;

        for(vector<int>::iterator it=nums.begin(); it!=nums.end();it++) {
            // 16 = 18 - 2
            // the difference between ‘target’ and current ‘number’
            diff = target - *it;

            if(index_map.find(diff) != index_map.end()) {
                ans.push_back(index_map[diff]);
                ans.push_back(it - nums.begin());
                break;
            }
            
            // save key:value = current_number:index
            index_map[*it] = it - nums.begin();
        }

        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution solution;
    int target = 106;
    int myints[] = {16,77,2,29};
    
    vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

    vector<int> ans = solution.twoSum(nums, target);
    // solution.twoSum(nums, target);
    cout << ans.front() << ' ' << ans.back() << endl;

    return 0;
}