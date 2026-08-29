```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            int ans = -1;

            // Find nums1[i] in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {

                    // Find next greater element
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[k] > nums2[j]) {
                            ans = nums2[k];
                            break;
                        }
                    }

                    break;
                }
            }

            result.push_back(ans);
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
