# Next Greater Element I — Brute Force

### Approach

For each element of `nums1`, find its position in `nums2`, then scan to the right and find the **first greater element**. If none exists, return `-1`.

### Complexity

* **Time:** O(n²)
* **Space:** O(n)

### Note

Prefix/suffix maximum does not work because we need the **nearest greater element**, not the maximum element. A **monotonic stack** is used for the optimized O(n) solution.

### optimal approach


# Next Greater Element I — Monotonic Stack

### Approach

Traverse `nums2` from right to left using a **monotonic decreasing stack**. Remove all elements smaller than or equal to the current element; the stack top is the next greater element.

Store each answer in an `unordered_map` and use it to get answers for `nums1`.

### Complexity

* **Time:** O(n + m) average
* **Space:** O(n)

### Note

Prefix/suffix maximum cannot find the **nearest greater element**, so a monotonic stack is used.
