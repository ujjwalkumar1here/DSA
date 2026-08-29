```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int> st;
        unordered_map<int, int> mp;

        // Find Next Greater Element for every element in nums2
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }

            if (st.empty()) {
                mp[nums2[i]] = -1;
            }
            else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        // Get answers for nums1
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(mp[nums1[i]]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
```
