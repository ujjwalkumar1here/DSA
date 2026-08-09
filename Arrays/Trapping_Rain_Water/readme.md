# Trapping Rain Water (LeetCode 42)

## Problem

Given an array `height[]` where each element represents the height of a bar, find how much rain water can be trapped after raining.

Example:

```text
height = [4,2,0,3,2,5]
```

Output:

```text
9
```

---

# Key Formula

For every index `i`:

```text
water[i] = min(leftMax[i], rightMax[i]) - height[i]
```

Where:

* `leftMax[i]` = tallest bar on the left side including `i`
* `rightMax[i]` = tallest bar on the right side including `i`

The water level is determined by the **smaller wall**.

---

# 1. Brute Force Approach

### Idea

For every index:

1. Find the tallest bar on the left.
2. Find the tallest bar on the right.
3. Add:

```text
min(leftMax, rightMax) - height[i]
```

### Code

```cpp
int trap(vector<int>& height)
{
    int n = height.size();
    int water = 0;

    for(int i = 0; i < n; i++)
    {
        int leftMax = 0;
        int rightMax = 0;

        for(int j = 0; j <= i; j++)
            leftMax = max(leftMax, height[j]);

        for(int j = i; j < n; j++)
            rightMax = max(rightMax, height[j]);

        water += min(leftMax, rightMax) - height[i];
    }

    return water;
}
```

### Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)`

---

# 2. Better Approach (Prefix + Suffix)

### Idea

Avoid recalculating maxima repeatedly.

Create:

* `leftMax[]`
* `rightMax[]`

### Building Arrays

```cpp
leftMax[i] = max(leftMax[i-1], height[i]);
rightMax[i] = max(rightMax[i+1], height[i]);
```

### Code

```cpp
int trap(vector<int>& height)
{
    int n = height.size();

    vector<int> leftMax(n), rightMax(n);

    leftMax[0] = height[0];

    for(int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], height[i]);

    rightMax[n-1] = height[n-1];

    for(int i = n-2; i >= 0; i--)
        rightMax[i] = max(rightMax[i+1], height[i]);

    int water = 0;

    for(int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - height[i];

    return water;
}
```

### Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

---

# 3. Optimal Approach (Two Pointers)

### Most Important Observation ⭐⭐⭐⭐⭐

Suppose:

```text
leftMax  = 4
rightMax = 7
```

For the current **left** bar:

```text
water = min(4,7) - height[left]
      = 4 - height[left]
```

Notice that the **left side completely decides the water level**.

We do **not** need the exact value of `rightMax`; we only need to know that it is **greater than leftMax**.

Therefore:

* If `leftMax < rightMax`

  * Water is decided by **leftMax**
  * We calculate:

```cpp
water += leftMax - height[left];
```

* Otherwise

  * Water is decided by **rightMax**
  * We calculate:

```cpp
water += rightMax - height[right];
```

This is the reason the **two-pointer approach works**.

---

# Why Do We Subtract from the Left?

When:

```text
leftMax < rightMax
```

the smaller wall is `leftMax`.

So the trapped water on the left side is:

```text
leftMax - height[left]
```

That is why in the code we write:

```cpp
water += leftMax - height[left];
left++;
```

Similarly, when the right side is smaller:

```cpp
water += rightMax - height[right];
right--;
```

This is the **core interview explanation**.

---

# Optimal Code

```cpp
int trap(vector<int>& height)
{
    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while(left < right)
    {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);

        if(leftMax < rightMax)
        {
            // Left side decides
            water += leftMax - height[left];
            left++;
        }
        else
        {
            // Right side decides
            water += rightMax - height[right];
            right--;
        }
    }

    return water;
}
```

---

# Dry Run

Input:

```text
[4,2,0,3,2,5]
```

### Step 1

```text
leftMax = 4
rightMax = 5
```

Since:

```text
4 < 5
```

Water:

```text
4 - 4 = 0
```

Move `left`.

---

### Step 2

```text
left = 1
height = 2
```

Water:

```text
4 - 2 = 2
```

Total:

```text
2
```

---

### Step 3

```text
left = 2
height = 0
```

Water:

```text
4 - 0 = 4
```

Total:

```text
6
```

Continue similarly.

Final answer:

```text
9
```

---

# Complexity Comparison

| Approach    | Time  | Space |
| ----------- | ----- | ----- |
| Brute Force | O(n²) | O(1)  |
| Better      | O(n)  | O(n)  |
| Optimal     | O(n)  | O(1)  |

---

# Important Interview Points

### Why include the current index while calculating maxima?

Because:

```text
leftMax >= height[i]
rightMax >= height[i]
```

This guarantees:

```text
min(leftMax, rightMax) - height[i] >= 0
```

So trapped water is never negative.

---

### Why does the two-pointer approach work?

Because **the smaller maximum wall determines the water level**.

If:

```text
leftMax < rightMax
```

then:

```text
min(leftMax, rightMax) = leftMax
```

Therefore the water above the current left bar is already fixed, and we can safely process the left pointer without knowing future right values.

This is the key concept interviewers usually ask.

---

# Pattern

```text
Brute Force
      ↓
Prefix + Suffix
      ↓
Two Pointers
      ↓
Smaller Side Decides the Water
```

---

# Final Revision Line ⭐

> **In the optimal approach, whichever side has the smaller maximum height decides the trapped water for that side, so we subtract the current bar height from that smaller maximum and move that pointer inward.**
