# Shortest Path in Binary Matrix

Problem

You are given an n x n binary matrix.

0 -> Empty Cell

1 -> Blocked Cell

You start from

(0,0)

and want to reach

(n-1,n-1).

You can move in all 8 directions.

Return the length of the shortest clear path.

If no path exists, return -1.

----------------------------------------------------

Approach

Step 1

Check whether the starting or ending cell is blocked.

If yes,

return -1.

----------------------------------------------------

Step 2

Create a visited matrix.

visited[row][col]

stores whether a cell has already been visited.

----------------------------------------------------

Step 3

Create a queue.

Each queue element stores

{{row,col},distance}

Example

{{0,0},1}

----------------------------------------------------

Step 4

Push the starting cell into the queue.

Mark it visited.

----------------------------------------------------

Step 5

While the queue is not empty

Remove the front element.

If the current cell is the destination,

return its distance.

----------------------------------------------------

Step 6

Explore all 8 directions.

For every neighbour,

Check

• Inside the grid

• Not blocked

• Not visited

If all conditions are true,

Mark it visited.

Push it into the queue with

distance + 1.

----------------------------------------------------

Step 7

If BFS finishes without reaching the destination,

return -1.

----------------------------------------------------

Logic

BFS always explores cells level by level.

Since every move costs one step,

the first time we reach the destination

is guaranteed to be the shortest path.

----------------------------------------------------

Dry Run

Input

0 1

1 0

Queue

{{0,0},1}

visited

T F

F F

----------------------------------

Pop

(0,0)

Distance = 1

Neighbours

Only

(1,1)

is valid.

Push

{{1,1},2}

visited

T F

F T

----------------------------------

Pop

(1,1)

Destination reached.

Return

2

----------------------------------------------------

Example 2

Input

0 0 0

1 1 0

1 1 0

Shortest Path

(0,0)

↓

(0,1)

↓

(0,2)

↓

(1,2)

↓

(2,2)

Answer

5

----------------------------------------------------

Time Complexity

O(n²)

Reason

Each cell is visited at most once.

----------------------------------------------------

Space Complexity

O(n²)

Reason

Visited matrix + Queue.

----------------------------------------------------

Pattern Learned

Shortest Path using BFS

Whenever you see

• Start Position

• Destination

• Obstacles

• Minimum Steps

• Every move has equal cost

Think

BFS

----------------------------------------------------

Important Concepts

Queue stores

{{row,col},distance}

Visited matrix prevents visiting the same cell multiple times.

Direction Arrays

dr[] = {-1,-1,-1,0,0,1,1,1}

dc[] = {-1,0,1,-1,1,-1,0,1}

allow movement in all 8 directions.