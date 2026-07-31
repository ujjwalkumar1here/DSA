#include <bits/stdc++.h>
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

ListNode* reverseList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* temp = head;
    ListNode* prev = NULL;

    while(head != NULL)
    {
        head = head->next;
        temp->next = prev;
        prev = temp;
        temp = head;
    }

    return prev;
}

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed List: ";
    printList(head);

    return 0;
}