# Sort Colors (LeetCode 75)

## Approach 3 : Dutch National Flag Algorithm (Optimal)

### Idea

Instead of counting or sorting, divide the array into four regions.

At every step:

```text
0 ........ left-1      → All 0s

left ..... mid-1       → All 1s

mid ...... high        → Unknown Elements

high+1 ... n-1         → All 2s
```

Initially

```text
left = 0
mid = 0
high = n-1
```

The region between `mid` and `high` is unknown.

Our goal is to process every unknown element exactly once.

---

## Algorithm

Initialize

```cpp
left = 0;
mid = 0;
high = n - 1;
```

While

```cpp
mid <= high
```

### Case 1

If

```cpp
nums[mid] == 0
```

Swap

```cpp
nums[left]
```

and

```cpp
nums[mid]
```

Move

```cpp
left++;
mid++;
```

---

### Case 2

If

```cpp
nums[mid] == 1
```

It is already in the correct region.

Move

```cpp
mid++;
```

---

### Case 3

If

```cpp
nums[mid] == 2
```

Swap

```cpp
nums[mid]
```

with

```cpp
nums[high]
```

Move

```cpp
high--;
```

Do **not** increment `mid`.

---

## Why don't we increment `mid` after swapping with `high`?

Suppose

```text
[1,2,0]
```

Current pointers

```text
left = 0

mid = 1

high = 2
```

Swap

```text
2 ↔ 0
```

Array becomes

```text
[1,0,2]
```

The new element at `mid` is `0`.

It has **not been processed yet**.

If we increment `mid`, we skip checking it.

Therefore,

after swapping with `high`, we only do

```cpp
high--;
```

and check the new `nums[mid]` in the next iteration.

---

## Why do we increment both `left` and `mid` after placing a 0?

After swapping,

the element moved from `left` to `mid` has already been processed.

It belongs to the 1's region (or `left == mid`).

Therefore both pointers can safely move forward.

---

## Dry Run

Input

```text
[2,0,2,1,1,0]
```

Initial

```text
left = 0
mid = 0
high = 5
```

Process

```text
2

↓

Swap with high

↓

0 0 2 1 1 2

↓

Process 0

↓

0 0 2 1 1 2

↓

Process 0

↓

0 0 2 1 1 2

↓

Swap 2 with 1

↓

0 0 1 1 2 2

↓

Process remaining 1s
```

Final

```text
0 0 1 1 2 2
```

---

## Time Complexity

O(n)

Reason:

Each element is processed at most once.

---

## Space Complexity

O(1)

Reason:

Only three pointers are used.

---

## Important Points

✅ Three Pointer Technique

✅ One Traversal

✅ In-place Sorting

✅ No Extra Space

✅ Dutch National Flag Algorithm

---

## Pattern

Two Pointers + Partitioning