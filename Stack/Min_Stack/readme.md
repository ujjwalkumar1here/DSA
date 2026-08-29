# Min Stack

### Approach

Use a `stack<pair<int,int>>`. Store each value along with the **minimum value up to that point**.

* `first` → actual value
* `second` → minimum so far

This allows `getMin()` to work in **O(1)** time.

### Complexity

* Time: **O(1)** for push, pop, top and getMin
* Space: **O(n)**
