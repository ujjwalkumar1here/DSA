# Symmetric Tree (LeetCode 101)

## Idea

Compare the left subtree with the right subtree as a mirror.

---

## Base Cases

```cpp
if(left == NULL && right == NULL)
    return true;

if(left == NULL || right == NULL)
    return false;
```

---

## Recursive Formula

```cpp
return mirror(left->left, right->right) &&
       mirror(left->right, right->left);
```

---

## Dry Run

Tree

        1
      /   \
     2     2
    / \   / \
   3   4 4   3

Compare

2 ↔ 2 ✔

↓

3 ↔ 3 ✔

↓

4 ↔ 4 ✔

Answer = true

---

## Time Complexity

O(n)

---

## Space Complexity

O(h)

h = Height of Tree

---

## Important Points

✅ Both NULL → Symmetric

✅ One NULL → Not Symmetric

✅ Values must be equal.

✅ Compare Left-Left with Right-Right.

✅ Compare Left-Right with Right-Left.

---

## Pattern

Mirror DFS + Recursion

---

## Difference

Same Tree

Left ↔ Left

Right ↔ Right

Symmetric Tree

Left ↔ Right

Right ↔ Left