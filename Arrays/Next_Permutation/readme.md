# Next Permutation (LeetCode 31)

## Idea

Find the next lexicographically greater permutation.

---

## Algorithm

### Step 1

Find the pivot.

Traverse from right.

Find

```cpp
nums[i] < nums[i+1]
```

---

### Step 2

Find the first element greater than the pivot from the right.

Swap both elements.

---

### Step 3

Reverse the elements after the pivot.

---

## Example

Input

1 2 3 6 5 4

Pivot = 3

↓

Swap with 4

1 2 4 6 5 3

↓

Reverse

1 2 4 3 5 6

Output

1 2 4 3 5 6

---

## Special Case

Input

3 2 1

No pivot found.

Reverse the whole array.

Output

1 2 3

---

## Time Complexity

O(n)

---

## Space Complexity

O(1)

---

## Important Points

✅ Find Pivot

```cpp
nums[i] < nums[i+1]
```

✅ Swap with the first greater element from the right.

✅ Reverse the suffix.

✅ If no pivot exists, reverse the whole array.

---

## Pattern

Array + Greedy + Two Pointer (Reverse)