#include <iostream>
#include <vector>
#include <algorithm>
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    vector<int> arr;

    ListNode* a = list1;
    ListNode* b = list2;

    while(a != NULL)
    {
        arr.push_back(a->val);
        a = a->next;
    }

    while(b != NULL)
    {
        arr.push_back(b->val);
        b = b->next;
    }

    sort(arr.begin(), arr.end());

    if(arr.empty())
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    ListNode* merged = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}