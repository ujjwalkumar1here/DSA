#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // Closing brackets
            else {
                if (st.empty())
                    return false;

                if ((c == ')' && st.top() == '(') ||
                    (c == '}' && st.top() == '{') ||
                    (c == ']' && st.top() == '[')) {
                    st.pop();
                } 
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    string s;
    cin >> s;

    cout << boolalpha << sol.isValid(s) << endl;

    return 0;
}