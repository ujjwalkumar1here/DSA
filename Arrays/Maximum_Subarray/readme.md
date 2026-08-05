# Maximum Subarray Sum (LeetCode 53)

## Approach 3 : Kadane's Algorithm (Optimal)

### Idea

Keep a running sum.

- If the running sum becomes negative, discard it.
- A negative sum cannot increase the sum of any future subarray.
- Keep track of the maximum sum seen so far.

---

## Algorithm

1. Initialize

```cpp
currSum = 0;
maxi = INT_MIN;
```

2. Traverse the array.

3. Add the current element to `currSum`.

4. Update the maximum answer.

5. If `currSum` becomes negative, reset it to `0`.

---

## Example

Input

```text
[-2,1,-3,4,-1,2,1,-5,4]
```

Running Sum

```text
-2 → reset to 0

1

-2 → reset

4

3

5

6

1

5
```

Maximum Sum

```text
6
```

---

## Why Kadane's Algorithm Works

If the running sum becomes negative,

adding it to any future subarray will only decrease that future sum.

So it is always better to start a new subarray.

Example

```text
Current Sum = -5

Next Element = 10

Option 1

-5 + 10 = 5

Option 2

10

Better Answer = 10
```

Therefore, discard the negative running sum.

---

## Time Complexity

O(n)

Reason:

- Single traversal of the array.

---

## Space Complexity

O(1)

---

## Important Points

✅ Single traversal.

✅ Running Sum.

✅ Reset only when running sum becomes negative.

✅ Update maximum before resetting.

---

## Pattern

Array + Kadane's Algorithm