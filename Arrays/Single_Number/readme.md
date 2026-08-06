# Single Number (LeetCode 136)

## Approach : Bit Manipulation (XOR)

### Idea

Every number appears twice except one.

The XOR operator (`^`) has special properties:

- `a ^ a = 0`
- `a ^ 0 = a`
- XOR is commutative.
- XOR is associative.

Therefore, all duplicate numbers cancel each other, leaving only the unique number.

---

## Algorithm

1. Initialize

```cpp
int ans = 0;
```

2. Traverse the array.

3. XOR every element with `ans`.

```cpp
ans = ans ^ nums[i];
```

4. Return `ans`.

---

## Example

Input

```text
[4,1,2,1,2]
```

Process

```text
ans = 0

0 ^ 4 = 4

4 ^ 1 = 5

5 ^ 2 = 7

7 ^ 1 = 6

6 ^ 2 = 4
```

Final Answer

```text
4
```

---

## Why XOR Works

Consider

```text
2 ^ 3 ^ 2
```

Using associativity,

```text
2 ^ 2 ^ 3
```

Now,

```text
2 ^ 2 = 0
```

So,

```text
0 ^ 3 = 3
```

Every duplicate pair becomes `0`.

Only the unique element remains.

---

## XOR Properties

```text
a ^ a = 0

a ^ 0 = a

a ^ b = b ^ a

(a ^ b) ^ c = a ^ (b ^ c)
```

---

## Dry Run

Input

```text
[2,2,1]
```

Initially

```text
ans = 0
```

Iteration 1

```text
ans = 0 ^ 2 = 2
```

Iteration 2

```text
ans = 2 ^ 2 = 0
```

Iteration 3

```text
ans = 0 ^ 1 = 1
```

Answer

```text
1
```

---

## Time Complexity

O(n)

Reason:

- Traverse the array only once.

---

## Space Complexity

O(1)

Reason:

- Only one variable is used.

---

## Important Points

✅ XOR of the same numbers is 0.

✅ XOR with 0 gives the same number.

✅ Order of XOR operations does not matter.

✅ Duplicate numbers cancel each other automatically.

---

## Pattern

Bit Manipulation + XOR