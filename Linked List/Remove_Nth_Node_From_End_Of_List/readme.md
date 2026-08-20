# Remove Nth Node From End of List

Approach

Step 1

Create a dummy node and connect it to the head.

dummy -> head

Step 2

Initialize two pointers.

slow = dummy
fast = dummy

Step 3

Move the fast pointer (n + 1) steps ahead.

for(int i = 0; i <= n; i++)
{
    fast = fast->next;
}

This creates a gap of n nodes between slow and fast.

Step 4

Move both pointers one step at a time.

while(fast != NULL)
{
    slow = slow->next;
    fast = fast->next;
}

When fast reaches NULL, slow will be just before the node that needs to be removed.

Step 5

Delete the target node.

slow->next = slow->next->next;

Step 6

Return dummy->next because the dummy node is not part of the final linked list.

Why Dummy Node?

A dummy node creates a node before the head.

Without a dummy node, deleting the head requires writing a separate special case.

With a dummy node, the same logic works for deleting any node, including the head.

Logic

Maintain a fixed gap of n nodes between fast and slow.

Initially move fast (n + 1) steps ahead.

Then move both pointers together.

When fast becomes NULL:

- slow points to the node just before the node to delete.

Delete the node by updating:

slow->next = slow->next->next;

Dry Run

Input

1 -> 2 -> 3 -> 4 -> 5

n = 2

Initial

dummy -> 1 -> 2 -> 3 -> 4 -> 5

slow = dummy
fast = dummy

Move fast 3 steps

dummy -> 1 -> 2 -> 3 -> 4 -> 5
slow              fast

Move both pointers

Iteration 1

dummy -> 1 -> 2 -> 3 -> 4 -> 5
      slow              fast

Iteration 2

dummy -> 1 -> 2 -> 3 -> 4 -> 5
           slow              fast(NULL)

Now slow points to node 3.

Delete

slow->next = slow->next->next;

Result

1 -> 2 -> 3 -> 5

Example 2

Input

1

n = 1

dummy -> 1

Delete node 1.

Output

NULL

Time Complexity

O(n)

Space Complexity

O(1)