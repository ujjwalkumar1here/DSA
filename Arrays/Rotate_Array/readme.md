# Rotate Array Using Reversal Algorithm

## Problem

Given an array, rotate it to the **right by `k` positions**.

### Example

```text
Input:
nums = [1, 2, 3, 4, 5, 6, 7]
k = 3

Output:
[5, 6, 7, 1, 2, 3, 4]
```

---

## Approach: Reversal Algorithm

The array can be rotated in-place using **3 reversals**.

For:

```text
nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
```

We divide the array into two parts:

```text
First n-k elements       Last k elements
[1, 2, 3, 4]             [5, 6, 7]
```

Then perform the following operations.

### Step 1: Reverse the first `n-k` elements

```cpp
reverse(nums.begin(), nums.begin() + n - k);
```

Before:

```text
[1, 2, 3, 4] [5, 6, 7]
```

After:

```text
[4, 3, 2, 1] [5, 6, 7]
```

### Important: Included and Excluded Elements

C++ STL `reverse()` follows the range:

```cpp
reverse(first, last);
```

It reverses:

```text
[first, last)
```

This means:

* `first` → **included**
* `last` → **excluded**

Therefore:

```cpp
reverse(nums.begin(), nums.begin() + n - k);
```

reverses:

```text
index:  0   1   2   3 | 4   5   6
       [1] [2] [3] [4] | 5   6   7
        ↑               ↑
     included        excluded
```

`nums.begin() + n-k` points to index `4`, so **index 4 is NOT included** in the first reverse.

---

## Step 2: Reverse the last `k` elements

```cpp
reverse(nums.begin() + n - k, nums.end());
```

Now:

```text
[4, 3, 2, 1] [5, 6, 7]
```

becomes:

```text
[4, 3, 2, 1] [7, 6, 5]
```

Here:

```cpp
nums.begin() + n - k
```

points to index `4`, so index `4` **is included in the second reverse**.

Therefore, there is **no overlap**.

The ranges are:

```text
First reverse:
[0, n-k)

Second reverse:
[n-k, n)
```

They meet exactly at `n-k`, but that element belongs only to the **second range**.

---

## Step 3: Reverse the entire array

```cpp
reverse(nums.begin(), nums.end());
```

Before:

```text
[4, 3, 2, 1, 7, 6, 5]
```

After:

```text
[5, 6, 7, 1, 2, 3, 4]
```

This is the required right rotation by `3`.

---

## Why Does This Work?

Suppose the array is divided into:

```text
A = first n-k elements
B = last k elements
```

Initially:

```text
A B
```

After reversing both parts:

```text
reverse(A) reverse(B)
```

After reversing the entire array:

```text
B A
```

So the last `k` elements move to the front, which is exactly a **right rotation by `k` positions**.

---

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k)
{
    int n = nums.size();

    k = k % n;

    // Reverse first n-k elements
    reverse(nums.begin(), nums.begin() + n - k);

    // Reverse last k elements
    reverse(nums.begin() + n - k, nums.end());

    // Reverse the entire array
    reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    int k = 3;

    rotate(nums, k);

    cout << "Rotated Array: ";

    for(int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}
```

### Output

```text
Rotated Array: 5 6 7 1 2 3 4
```

---

## Why `k = k % n`?

If `k` is greater than the array size, rotating by `n` positions brings the array back to its original form.

For example:

```text
n = 7

k = 10
```

Rotating 10 times is equivalent to rotating:

```text
10 % 7 = 3
```

So:

```cpp
k = k % n;
```

avoids unnecessary rotations.

---

## Complexity

### Time Complexity

```text
O(n)
```

There are three reversals, and each reversal takes linear time.

```text
O(n) + O(n) + O(n) = O(n)
```

### Space Complexity

```text
O(1)
```

The array is modified **in-place**, so no additional array is required.

---

## Key STL Concept: Half-Open Ranges

C++ STL algorithms commonly use the range:

```text
[first, last)
```

Remember:

```text
first → INCLUDED
last  → EXCLUDED
```

For example:

```cpp
reverse(nums.begin(), nums.begin() + 4);
```

reverses indices:

```text
0, 1, 2, 3
```

but does **not** reverse index:

```text
4
```

### Quick Rule

```text
[begin, begin + x)
 ↑             ↑
included     excluded
```

This concept is very important for STL algorithms such as:

* `reverse()`
* `sort()`
* `lower_bound()`
* `upper_bound()`
* `vector` iterators

---

## Key Takeaways

1. `reverse()` uses a **half-open range `[first, last)`**.
2. The first argument is **included**.
3. The second argument is **excluded**.
4. `n-k` is **excluded from the first reverse**.
5. `n-k` is **included in the second reverse**.
6. Therefore, the two ranges **do not overlap**.
7. `k = k % n` handles `k > n`.
8. The algorithm works **in-place**.
9. Time Complexity: **O(n)**.
10. Space Complexity: **O(1)**.
11. The technique is known as the **Reversal Algorithm** for array rotation.
