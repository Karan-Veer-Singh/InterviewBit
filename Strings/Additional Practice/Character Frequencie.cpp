vector<int> Solution::solve(string A)
{
    map<char, int> m;
    vector<int> ans;

    for (char ch : A)
        m[ch]++;

    for (char ch : A)
        if (m[ch] > 0) {
            ans.push_back(m[ch]);
            m[ch] = 0;
        }

    return ans;
}


// https://www.interviewbit.com/problems/character-frequencies/