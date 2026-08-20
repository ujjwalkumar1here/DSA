# Remove Loop in Linked List

Problem

Given a linked list that may contain a loop, remove the loop without losing any nodes.

Example

Input

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

Output

1 -> 2 -> 3 -> 4 -> 5 -> NULL

----------------------------------------------------

Approach 1 (Brute Force - Hash Set)

Idea

Traverse the linked list from the head.

Store the address of every visited node inside a Hash Set.

If a node is encountered again, it means a loop exists.

The previous node's next pointer is changed to NULL to break the loop.

Algorithm

Step 1

Create an empty Hash Set.

set<Node*> st;

Step 2

Initialize

temp = head

prev = NULL

Step 3

Traverse the linked list.

While temp is not NULL

Check whether temp is already present in the Hash Set.

Step 4

If temp is already present,

prev->next = NULL

Return.

Step 5

Otherwise,

Insert temp into the Hash Set.

Move both pointers.

prev = temp

temp = temp->next

----------------------------------------------------

Dry Run (Hash Set)

Input

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

Initially

Set = {}

temp = 1

prev = NULL

----------------------------------

Visit 1

Set = {1}

prev = 1

temp = 2

----------------------------------

Visit 2

Set = {1,2}

prev = 2

temp = 3

----------------------------------

Visit 3

Set = {1,2,3}

prev = 3

temp = 4

----------------------------------

Visit 4

Set = {1,2,3,4}

prev = 4

temp = 5

----------------------------------

Visit 5

Set = {1,2,3,4,5}

prev = 5

temp = 3

----------------------------------

Node 3 is already present.

Break the loop.

prev->next = NULL

Result

1 -> 2 -> 3 -> 4 -> 5 -> NULL

----------------------------------------------------

Time Complexity

O(n)

Space Complexity

O(n)

----------------------------------------------------

Approach 2 (Optimal - Floyd's Cycle Detection)

Idea

Use Slow and Fast pointers.

First detect whether a loop exists.

If a loop exists,

find the starting node of the loop.

Then find the last node inside the loop.

Finally,

set the last node's next pointer to NULL.

----------------------------------------------------

Algorithm

Step 1

Initialize

slow = head

fast = head

----------------------------------------------------

Step 2

Move

slow = slow->next

fast = fast->next->next

until

slow == fast

If fast reaches NULL,

there is no loop.

Return.

----------------------------------------------------

Step 3

Move slow back to the head.

Keep fast at the meeting point.

slow = head

----------------------------------------------------

Step 4

Move both pointers one step at a time.

slow = slow->next

fast = fast->next

The node where they meet is the starting node of the loop.

----------------------------------------------------

Step 5

Create

temp = slow

Move temp until

temp->next == slow

Now temp points to the last node of the loop.

----------------------------------------------------

Step 6

Break the loop.

temp->next = NULL

----------------------------------------------------

Dry Run (Optimal)

Input

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

Phase 1

Detect Loop

Slow and Fast meet at node 4.

----------------------------------

Phase 2

Move slow to head.

slow = 1

fast = 4

Move both.

2 , 5

↓

3 , 3

They meet at node 3.

Node 3 is the starting node of the loop.

----------------------------------

Phase 3

temp = 3

Move

3

↓

4

↓

5

Now

temp->next = 3

Stop.

----------------------------------

Break Loop

5->next = NULL

Final List

1 -> 2 -> 3 -> 4 -> 5 -> NULL

----------------------------------------------------

Time Complexity

O(n)

Space Complexity

O(1)

----------------------------------------------------

Comparison

Hash Set

Time : O(n)

Space : O(n)

Easy to understand and implement.

----------------------------------------------------

Floyd's Algorithm

Time : O(n)

Space : O(1)

Optimal solution.

Preferred in interviews.

----------------------------------------------------

Pattern Learned

Fast & Slow Pointer (Floyd's Algorithm)

Related Questions

• Linked List Cycle (LeetCode 141)

• Linked List Cycle II (LeetCode 142)

• Remove Loop in Linked List (GeeksforGeeks)

----------------------------------------------------

Important  Notes

1. Never use

set<int>

Store node addresses instead.

Correct

set<Node*>

because multiple nodes can have the same value.

----------------------------------------------------

2. Floyd's Algorithm consists of three steps.

Detect the loop.

↓

Find the starting node of the loop.

↓

Find the last node in the loop and break it.

----------------------------------------------------

3. If the interviewer first asks for any solution,

explain the Hash Set approach.

If they ask for an optimized solution,

use Floyd's Cycle Detection Algorithm.