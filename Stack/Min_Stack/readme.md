# Min Stack - LeetCode 155

## Approach

We need to implement a stack that supports:

- `push()`
- `pop()`
- `top()`
- `getMin()`

All operations should work in **O(1)** time.

The main problem is `getMin()`.

If we search the complete stack every time to find the minimum, it would take **O(n)**.

### Key Idea

Store two values for every element:

```cpp
{value, minimum_so_far}
```

We use:

```cpp
stack<pair<int, int>> st;
```

The first value stores the actual element.

The second value stores the minimum element in the stack up to that point.

---

## Push Operation

If the stack is empty:

```cpp
st.push({val, val});
```

Otherwise:

```cpp
int minimum = min(val, st.top().second);

st.push({val, minimum});
```

We compare the current value with the previous minimum.

---

## Example

Operations:

```text
push(-2)
push(0)
push(-3)
```

Stack becomes:

```text
Value    Minimum
----------------
 -3        -3
  0        -2
 -2        -2
```

Therefore:

```cpp
getMin()
```

can directly return:

```cpp
st.top().second
```

Answer:

```text
-3
```

---

## Why Store Minimum With Every Element?

Suppose the current minimum is `-3`.

If we pop `-3`, we need to know what the previous minimum was.

Because every element stores its own `minimum_so_far`, the previous minimum is automatically available.

Before pop:

```text
Value    Minimum
----------------
 -3        -3
  0        -2
 -2        -2
```

After popping `-3`:

```text
Value    Minimum
----------------
  0        -2
 -2        -2
```

So the minimum automatically becomes `-2`.

---

## Operations

### Push

```cpp
void push(int val)
{
    if(st.empty())
    {
        st.push({val, val});
    }
    else
    {
        int minimum = min(val, st.top().second);
        st.push({val, minimum});
    }
}
```

### Pop

```cpp
void pop()
{
    st.pop();
}
```

### Top

```cpp
int top()
{
    return st.top().first;
}
```

### Get Minimum

```cpp
int getMin()
{
    return st.top().second;
}
```

---

## Complete Code

```cpp
#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;

public:

    void push(int val)
    {
        if(st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int minimum = min(val, st.top().second);
            st.push({val, minimum});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{
    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    return 0;
}
```

## Output

```text
Minimum: -3
Top: 0
Minimum: -2
```

---

## Complexity

| Operation | Time |
|-----------|------|
| `push()` | O(1) |
| `pop()` | O(1) |
| `top()` | O(1) |
| `getMin()` | O(1) |

### Space Complexity

```text
O(n)
```

Because we store one pair for every element.

---

## Important Points

1. Store:

```text
{value, minimum_so_far}
```

2. `getMin()` directly accesses:

```cpp
st.top().second
```

3. No traversal of the stack is required.

4. When the minimum is popped, the previous minimum is already stored below it.

5. The main goal is to make `getMin()` **O(1)**.

---

## DSA Pattern

```text
Normal Stack
     ↓
Need minimum in O(1)
     ↓
Store extra information
     ↓
{value, minimum_so_far}
     ↓
getMin() in O(1)
```

### Pattern to Remember

**Stack + Auxiliary Information**

This technique of storing extra information with each element is useful in many stack-based problems.