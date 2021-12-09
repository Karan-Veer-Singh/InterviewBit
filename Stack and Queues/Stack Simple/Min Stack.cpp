stack<int> s;
stack<int> ms;

MinStack::MinStack() {
    while (!s.empty())   s.pop();
    while (!ms.empty())  ms.pop();
}

void MinStack::push(int x) {
    s.push(x);
    if (ms.empty() || x < ms.top())
        ms.push(x);
}

void MinStack::pop() {
    if (s.empty())
        return;

    if (s.top() == ms.top())
        ms.pop();

    s.pop();
}

int MinStack::top() {
    if (s.empty())
        return -1;

    return s.top();
}

int MinStack::getMin() {
    if (ms.empty())
        return -1;

    return ms.top();
}

// https://www.interviewbit.com/problems/min-stack/submissions/