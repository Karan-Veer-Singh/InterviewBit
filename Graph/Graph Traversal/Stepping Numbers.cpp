void bfs(int n, int m, int num, vector<int> &ans)
{
    // Queue will contain all the stepping Numbers
    queue<int> q;
    q.push(num);

    while (!q.empty())
    {
        // Get the front element and pop from the queue
        int stepNum = q.front();
        q.pop();

        // If the Stepping Number is in the range
        // [n, m] then display
        if (stepNum <= m && stepNum >= n)
            ans.push_back(stepNum);

        // If Stepping Number is 0 or greater than m,
        // no need to explore the neighbors
        if (num == 0 || stepNum > m)
            continue;

        // Get the last digit of the currently visited
        // Stepping Number
        int lastDigit = stepNum % 10;

        // There can be 2 cases either digit to be
        // appended is lastDigit + 1 or lastDigit - 1
        int stepNumA = stepNum * 10 + (lastDigit - 1);
        int stepNumB = stepNum * 10 + (lastDigit + 1);

        // If lastDigit is 0 then only possible digit
        // after 0 can be 1 for a Stepping Number
        if (lastDigit == 0)
            q.push(stepNumB);

        //If lastDigit is 9 then only possible
        //digit after 9 can be 8 for a Stepping
        //Number
        else if (lastDigit == 9)
            q.push(stepNumA);

        else
        {
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;

    for (int i = 0 ; i <= 9 ; i++)
        bfs(A, B, i, ans);

    sort(ans.begin(), ans.end());
    return ans;
}

// https://www.interviewbit.com/problems/stepping-numbers/