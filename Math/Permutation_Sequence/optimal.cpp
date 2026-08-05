#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getPermutation(int n, int k)
{
    vector<int> numbers;
    int fact = 1;

    // Calculate (n-1)! and store numbers
    for(int i = 1; i < n; i++)
    {
        fact *= i;
        numbers.push_back(i);
    }

    numbers.push_back(n);

    // Convert to 0-based indexing
    k--;

    string ans = "";

    while(true)
    {
        int index = k / fact;

        ans += to_string(numbers[index]);

        numbers.erase(numbers.begin() + index);

        if(numbers.size() == 0)
            break;

        k = k % fact;

        fact = fact / numbers.size();
    }

    return ans;
}

int main()
{
    int n = 4;
    int k = 17;

    cout << "Kth Permutation : " << getPermutation(n, k);

    return 0;
}