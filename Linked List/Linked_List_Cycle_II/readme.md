# Linked List Cycle II

Approach

Step 1

If the linked list is empty or contains only one node, return NULL.

Step 2

Initialize two pointers:
- slow = head
- fast = head

Step 3

Traverse the linked list while:
- fast != NULL
- fast->next != NULL

Step 4

Move the slow pointer one step forward.

slow = slow->next

Step 5

Move the fast pointer two steps forward.

fast = fast->next->next

Step 6

If slow == fast, a cycle is detected. Exit the loop.

Step 7

If fast == NULL or fast->next == NULL, no cycle exists. Return NULL.

Step 8

Move the slow pointer back to the head.

slow = head

Step 9

Move both slow and fast one step at a time until they meet.

slow = slow->next
fast = fast->next

Step 10

Return slow because it points to the starting node of the cycle.

Logic

The first phase detects whether a cycle exists using the Fast and Slow Pointer technique.

After the meeting point is found, move one pointer to the head while keeping the other at the meeting point.

Move both pointers one step at a time.

The node where they meet again is the starting node of the cycle.

Dry Run

Input

3 -> 2 -> 0 -> -4
     ^         |
     |_________|

Initial

slow = 3
fast = 3

Iteration 1

slow = 2
fast = 0

Iteration 2

slow = 0
fast = 2

Iteration 3

slow = -4
fast = -4

slow == fast

Cycle Detected.

Move slow back to head.

slow = 3
fast = -4

Iteration 1

slow = 2
fast = 2

slow == fast

Return node with value 2.

Example (No Cycle)

Input

1 -> 2 -> 3 -> NULL

The fast pointer reaches NULL.

Return NULL.

Time Complexity

O(n)

Space Complexity

O(1)