# Find Missing and Repeated Values (LeetCode 2965)

## Approach : Set + Sum Formula

### Idea

Use a set to find the repeated number.

Use the sum formula to calculate the missing number.

---

## Algorithm

1. Traverse the grid.
2. Insert every number into a set.
3. If a number is already present in the set, it is the repeated number.
4. Calculate the actual sum of all elements.
5. Calculate the expected sum from `1` to `n²`.
6. Find the missing number using:

```text
Missing = Expected Sum - (Actual Sum - Repeated)
```

7. Return the repeated and missing numbers.

---

## Formula

```text
Actual Sum

=

Expected Sum - Missing + Repeated
```

Rearranging,

```text
Missing

=

Expected Sum - (Actual Sum - Repeated)
```

---

## Example

Input

```text
1 3
2 2
```

Expected Numbers

```text
1 2 3 4
```

Repeated

```text
2
```

Missing

```text
4
```

---

## Time Complexity

O(n² log n)

Reason:

- Traverse all cells.
- Each set insertion/search takes O(log n).

---

## Space Complexity

O(n²)

Reason:

- Set stores up to `n²` elements.

---

## Important Points

✅ Use a set to detect duplicates.

✅ Compute the actual sum while traversing.

✅ Expected numbers range from `1` to `n²`.

✅ Apply the sum formula to find the missing value.

---

## Pattern

Math + Set