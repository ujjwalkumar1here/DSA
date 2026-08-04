# Three Sum (LeetCode 15)

## Idea

1. Sort the array.
2. Fix one element.
3. Use two pointers to find the remaining two elements.

---

## Algorithm

1. Sort the array.
2. Traverse using index `i`.
3. Skip duplicate values of `i`.
4. Set

```cpp
left = i + 1;
right = n - 1;
```

5. Calculate

```cpp
sum = nums[i] + nums[left] + nums[right];
```

- If sum == 0 → Store triplet.
- If sum < 0 → Move left.
- If sum > 0 → Move right.

6. Skip duplicate left and right values.

---

## Example

Input

[-1,0,1,2,-1,-4]

Sorted

[-4,-1,-1,0,1,2]

Output

[-1,-1,2]

[-1,0,1]

---

## Time Complexity

O(n²)

---

## Space Complexity

O(1)

(Excluding output vector)

---

## Important Points

✅ Sort the array first.

✅ Fix one element.

✅ Use Two Pointers.

✅ Skip duplicate values.

---

## Pattern

Sorting + Two Pointers