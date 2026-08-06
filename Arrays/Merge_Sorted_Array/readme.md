# Merge Sorted Array (LeetCode 88)

## Approach 2 : Three Pointers (Optimal)

### Idea

Instead of merging from the beginning, merge from the **end**.

The last `n` positions of `nums1` are empty, so we can safely fill them without overwriting useful elements.

Use three pointers:

- `left1` → Last valid element of `nums1`
- `left2` → Last element of `nums2`
- `index` → Last position of `nums1`

Compare both elements and place the larger one at `index`.

Move the corresponding pointer and continue.

---

## Algorithm

1. Initialize

```cpp
left1 = m - 1;
left2 = n - 1;
index = m + n - 1;
```

2. Compare

```cpp
nums1[left1]
```

and

```cpp
nums2[left2]
```

3. Place the larger element at

```cpp
nums1[index]
```

4. Move the pointer of the copied element.

5. Decrease `index`.

6. Continue until one array finishes.

7. Copy the remaining elements of `nums2` if any.

---

## Example

Input

```text
nums1 = [1,2,3,0,0,0]

nums2 = [2,5,6]
```

Process

```text
Compare 3 and 6

Place 6

Compare 3 and 5

Place 5

Compare 3 and 2

Place 3

Compare 2 and 2

Place 2

Compare 1 and 2

Place 2

Remaining

1
```

Output

```text
1 2 2 3 5 6
```

---

## Why do we only copy the remaining elements of nums2?

Suppose

```text
nums1 = [1,2,3,0,0,0]

nums2 = [4,5,6]
```

We place

```text
6

↓

5

↓

4
```

Result becomes

```text
1 2 3 4 5 6
```

Notice that

```text
1 2 3
```

never moved.

They were already in the correct positions.

Therefore, if `left2` finishes first, the remaining elements of `nums1` are already in the correct position, so there is **no need** to copy them again.

However, if `left1` finishes first, some elements of `nums2` are still left, and they **must** be copied into `nums1`.

That's why we only keep:

```cpp
while(left2 >= 0)
{
    nums1[index] = nums2[left2];
    left2--;
    index--;
}
```

---

## Time Complexity

O(m + n)

Every element is processed once.

---

## Space Complexity

O(1)

No extra array is used.

---

## Important Points

✅ Three Pointers

✅ Start merging from the end.

✅ Compare larger elements.

✅ Fill the empty positions of `nums1`.

✅ Copy only the remaining elements of `nums2`.

---

## Pattern

Two Pointers + In-place Merge