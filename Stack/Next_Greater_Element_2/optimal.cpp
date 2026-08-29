```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // Traverse the array twice to handle circular nature
        for (int i = 2 * n - 1; i >= 0; i--) {
            int current = nums[i % n];

            while (!st.empty() && current >= st.top()) {
                st.pop();
            }

            if (i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }

            st.push(current);
        }

        return nge;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 1};

    vector<int> result = sol.nextGreaterElements(nums);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
```
