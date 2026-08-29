# Valid Parentheses

### Approach

Use a **stack** to store opening brackets.
For every closing bracket, check whether it matches the stack's top. If it matches, pop it; otherwise, return `false`.

At the end, the stack must be empty for the string to be valid.

### Complexity

* **Time:** O(n)
* **Space:** O(n)

### Key Concept

**Stack — LIFO (Last In, First Out)**
