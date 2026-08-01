class Solution {
public:
    void removeLoop(Node* head) {

        if(head == NULL)
            return;

        set<Node*> st;

        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL)
        {
            if(st.find(temp) != st.end())
            {
                prev->next = NULL;
                return;
            }

            st.insert(temp);

            prev = temp;
            temp = temp->next;
        }
    }
};