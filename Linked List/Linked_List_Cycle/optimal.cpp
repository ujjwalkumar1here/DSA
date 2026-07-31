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

bool hasCycle(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}

int main()
{
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating a cycle
    head->next->next->next->next = head->next;

    if(hasCycle(head))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}