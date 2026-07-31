#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

ListNode* detectCycle(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Detect Cycle
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    // No Cycle
    if(fast == NULL || fast->next == NULL)
        return NULL;

    // Step 2: Find Starting Node of Cycle
    slow = head;

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating Cycle
    fourth->next = second;

    ListNode* startNode = detectCycle(head);

    if(startNode != NULL)
        cout << "Cycle starts at node: " << startNode->val << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}