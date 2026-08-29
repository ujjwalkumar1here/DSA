# Next Greater Element II

### Approach

Use a **monotonic decreasing stack** and traverse the array `2n` times to simulate the circular array.

Use `i % n` to access elements circularly. Remove smaller/equal elements from the stack; the top is the next greater element.

### Complexity

* **Time:** O(n)
* **Space:** O(n)

### Optimization

Instead of physically duplicating the array, use `i % n` to simulate it, reducing extra array space.
