# Permutation Sequence (LeetCode 60)

## Idea

Instead of generating all permutations,

directly find the kth permutation using factorials.

---

## Observation

After fixing one number,

the remaining numbers can be arranged in

```text
(n-1)!
```

ways.

So every first digit owns a block of

```text
(n-1)!
```

permutations.

---

## Algorithm

1. Store numbers from 1 to n.

2. Compute

```text
(n-1)!
```

3. Convert

```cpp
k--;
```

to make indexing 0-based.

4. Find

```cpp
index = k / fact;
```

5. Choose

```cpp
numbers[index]
```

6. Remove the chosen number.

7. Update

```cpp
k = k % fact;
```

8. Update

```cpp
fact = fact / numbers.size();
```

9. Repeat until all numbers are used.

---

## Example

Input

```text
n = 4
k = 17
```

Output

```text
3412
```

---

## Why 0-Based Indexing?

Humans count

```text
1st, 2nd, 3rd...
```

Computers count

```text
0, 1, 2...
```

So we do

```cpp
k--;
```

This makes

```text
17th permutation

↓

Index 16
```

which allows

```cpp
index = k / fact;
```

to work correctly.

---

## Time Complexity

O(n²)

Reason:

- Loop runs n times.
- vector.erase() takes O(n).

---

## Space Complexity

O(n)

---

## Important Points

✅ No recursion.

✅ No next_permutation().

✅ No backtracking.

✅ Uses factorial mathematics.

✅ Choose one digit at a time.

---

## Pattern

Math + Factorial Number System