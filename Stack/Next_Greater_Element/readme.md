# Next Greater Element I — Brute Force

### Approach

For each element of `nums1`, find its position in `nums2`, then scan to the right and find the **first greater element**. If none exists, return `-1`.

### Complexity

* **Time:** O(n²)
* **Space:** O(n)

### Note

Prefix/suffix maximum does not work because we need the **nearest greater element**, not the maximum element. A **monotonic stack** is used for the optimized O(n) solution.

