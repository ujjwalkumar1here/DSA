# Find the Duplicate Number (LeetCode 287)

## Approach : Floyd's Cycle Detection (Tortoise and Hare)

### Idea

Treat the array as a linked list.

- Index → Current Node
- Value → Next Node

```cpp
next = nums[current];
```

Since one number is repeated, two different indices point to the same node.

This creates a cycle.

Use Floyd's Cycle Detection Algorithm to find the entrance of the cycle.

The entrance of the cycle is the duplicate number.

---

## Algorithm

### Phase 1

1. Initialize

```cpp
slow = nums[0];
fast = nums[0];
```

2. Move

```cpp
slow = nums[slow];
```

3. Move

```cpp
fast = nums[nums[fast]];
```

4. Continue until both pointers meet.

---

### Phase 2

1. Reset

```cpp
slow = nums[0];
```

2. Move both pointers one step.

3. The node where they meet is the duplicate number.

---

## Why do we use do-while?

Initially

```cpp
slow = nums[0];
fast = nums[0];
```

Both pointers are equal.

If we use a normal while loop,

the loop will never execute.

Using `do-while` guarantees that both pointers move at least once.

---

## Example

Input

```text
[1,3,4,2,2]
```

Connections

```text
0 → 1

1 → 3

3 → 2

2 → 4

4 → 2
```

Cycle

```text
2 → 4 → 2
```

Duplicate

```text
2
```

---

## Time Complexity

O(n)

---

## Space Complexity

O(1)

---

## Important Points

✅ Do not modify the array.

✅ No extra space.

✅ Uses Floyd's Cycle Detection.

✅ Array is treated like a linked list.

✅ Duplicate number is the entrance of the cycle.

---

## Pattern

Array + Linked List Concept + Floyd's Cycle Detection