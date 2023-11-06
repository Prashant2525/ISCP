/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.
*/

stack<int> s;
stack<int> t;
MinStack::MinStack()
{
    while (s.size() != 0)
    {
        s.pop();
    }
    while (t.size() != 0)
    {
        t.pop();
    }
}

void MinStack::push(int x)
{
    s.push(x);
    if (t.size() == 0)
    {
        t.push(x);
    }
    else
    {
        if (t.top() >= x)
        {
            t.push(x);
        }
    }
}

void MinStack::pop()
{
    if (s.size() != 0 && t.size() != 0 && s.top() == t.top())
    {
        s.pop();
        t.pop();
    }
    else
    {
        if (s.size() != 0)
        {
            s.pop();
        }
    }
}

int MinStack::top()
{
    if (s.size() != 0)
    {
        return s.top();
    }
    else
        return -1;
}

int MinStack::getMin()
{
    if (s.size() != 0 && t.size() != 0)
    {
        return t.top();
    }
    else
    {
        if (s.size() == 0)
            return -1;
    }
}
