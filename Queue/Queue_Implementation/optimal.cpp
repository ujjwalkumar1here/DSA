#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[100];
    int frontIndex;
    int rearIndex;

public:
    Queue()
    {
        frontIndex = 0;
        rearIndex = -1;
    }

    // Insert element
    void push(int x)
    {
        if(rearIndex == 99)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        rearIndex++;
        arr[rearIndex] = x;
    }

    // Remove element
    void pop()
    {
        if(empty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        frontIndex++;
    }

    // Front element
    int front()
    {
        if(empty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return arr[frontIndex];
    }

    // Check empty
    bool empty()
    {
        return frontIndex > rearIndex;
    }

    // Display queue
    void display()
    {
        if(empty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue: ";

        for(int i = frontIndex; i <= rearIndex; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    cout << "Front Element: " << q.front() << endl;

    q.pop();

    q.display();

    cout << "Front Element: " << q.front() << endl;

    return 0;
}