#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }

    // Push element
    void push(int x)
    {
        if(topIndex == 99)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        topIndex++;
        arr[topIndex] = x;
    }

    // Pop element
    void pop()
    {
        if(topIndex == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        topIndex--;
    }

    // Top element
    int top()
    {
        if(topIndex == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return arr[topIndex];
    }

    // Check empty
    bool empty()
    {
        return topIndex == -1;
    }

    // Display stack
    void display()
    {
        if(empty())
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        cout << "Stack: ";

        for(int i = topIndex; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top Element: " << st.top() << endl;

    st.pop();

    st.display();

    return 0;
}