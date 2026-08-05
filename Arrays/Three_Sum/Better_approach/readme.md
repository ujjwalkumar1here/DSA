# 3Sum (LeetCode 15) - Better Approach

## Idea

Instead of using three nested loops,

Fix one element and convert the remaining problem into **Two Sum**.

So,

```
3 Sum

↓

Fix one element

↓

2 Sum
```

---

## How Two Sum is Used

Suppose

```
nums = [-1,0,1,2,-1,-4]
```

Fix the first element

```
i = 0

nums[i] = -1
```

Now we need

```
-1 + x + y = 0
```

Move -1 to the other side

```
x + y = 1
```

Now the problem becomes **Two Sum**.

---

## Algorithm

For every index `i`

1. Create a new Hash Map.
2. Traverse from `j = i + 1`.
3. Calculate

```cpp
third = -(nums[i] + nums[j]);
```

4. If `third` already exists in the Hash Map,

Store the triplet.

Otherwise,

Store the current element in the Hash Map.

---

## Dry Run

Input

```
[-1,0,1,2,-1,-4]
```

Fix

```
i = 0

nums[i] = -1
```

Hash Map

```
{}
```

---

Take

```
j = 1

nums[j] = 0
```

Need

```
third = 1
```

Hash Map

```
{}
```

Not Found

Store

```
0
```

Hash Map

```
{0}
```

---

Next

```
j = 2

nums[j] = 1
```

Need

```
third = 0
```

Hash Map

```
{0}
```

Found

Triplet

```
[-1,0,1]
```

---

Next

```
j = 4

nums[j] = -1
```

Need

```
third = 2
```

Hash Map

```
{0,1,2}
```

Found

Triplet

```
[-1,-1,2]
```

---

## Why Hash Map?

Instead of searching the third element using another loop,

we search in

```cpp
unordered_map
```

Average lookup time

```
O(1)
```

So,

```
Three Loops

↓

Two Loops + Hash Map
```

---

## Time Complexity

```
O(n²)
```

---

## Space Complexity

```
O(n)
```

(Hash Map + Set)

---

## Important Points

✅ Fix one element.

✅ Remaining problem becomes Two Sum.

✅ Store visited numbers in Hash Map.

✅ Sort every triplet before inserting into the set.

✅ Set automatically removes duplicate triplets.

---

## Pattern

Array + Hash Map + Two Sum