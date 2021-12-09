stack<int> s;
int mini;

MinStack::MinStack() {
  while (!s.empty())
    s.pop();

  mini = INT_MAX;
}

void MinStack::push(int x) {
  if (s.empty())
  {
    s.push(x);
    mini = x;
  }
  else if (x < mini)
  {
    s.push(2 * x - mini);
    mini = x;
  }
  else
  {
    s.push(x);
  }
}

void MinStack::pop() {
  if (s.empty())
    return;

  int x = s.top();
  s.pop();

  if (x < mini)
    mini = 2 * mini - x;
}

int MinStack::top() {
  if (s.empty())
    return -1;

  int x = s.top();

  if (x < mini)
    return mini;
  else
    return x;
}

int MinStack::getMin() {
  if (s.empty())
    return -1;

  return mini;
}



// https://www.interviewbit.com/problems/min-stack/