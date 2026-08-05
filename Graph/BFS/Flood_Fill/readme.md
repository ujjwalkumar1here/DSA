# Flood Fill (LeetCode 733)

## Approach : BFS

### Idea

Start BFS from the given source cell.

Visit every neighbouring cell having the same original color.

Change its color and continue the BFS.

---

## Algorithm

1. Store the original color.

2. If original color and new color are the same, return the image.

3. Push the starting cell into the queue.

4. Change its color.

5. Visit all 4 neighbours.

6. If a neighbour:
   - is inside the grid,
   - has the original color,
   - is not visited,

   then:
   - change its color,
   - mark it visited,
   - push it into the queue.

7. Return the updated image.

---

## Directions

```cpp
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
```

| Direction | Row | Col |
|-----------|----:|----:|
| Up | -1 | 0 |
| Right | 0 | 1 |
| Down | 1 | 0 |
| Left | 0 | -1 |

---

## Time Complexity

O(N × M)

Every cell is visited at most once.

---

## Space Complexity

O(N × M)

- Visited matrix
- Queue (worst case)

---

## Important Points

✅ BFS on a grid.

✅ Use Queue.

✅ Store the original color before changing it.

✅ If original color equals new color, return immediately.

✅ Visit only cells having the original color.

---

## Pattern

Graph BFS

Grid Traversal