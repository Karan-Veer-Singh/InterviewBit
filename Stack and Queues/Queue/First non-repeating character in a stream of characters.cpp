string Solution::solve(string A)
{
    queue<char> q;
    int freq[256] = {0};
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (q.empty())
            ans += "#";
        else
            ans += q.front();
    }

    return ans;
}


// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/