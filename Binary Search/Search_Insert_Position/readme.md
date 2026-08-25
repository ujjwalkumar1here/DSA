# Search Insert Position

Approach

Step 1
Initialize two pointers, left and right, at the beginning and end of the sorted array.

Step 2
Calculate the middle index.

Step 3
If the middle element is equal to the target, return its index.

Step 4
If the target is smaller than the middle element, search in the left half.

Step 5
If the target is greater than the middle element, search in the right half.

Step 6
Repeat until the search space becomes empty.

Step 7
If the target is not found, return the left pointer because after the loop ends, left points to the correct insertion position.

Note

When the loop ends, right < left.
All elements before left are smaller than the target, and all elements from left onward are greater than or equal to the target. Therefore, left is the correct insertion index.

Time Complexity
O(log n)

Space Complexity
O(1)