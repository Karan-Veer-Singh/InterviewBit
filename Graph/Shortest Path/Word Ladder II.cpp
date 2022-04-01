void dfs(vector<string>&temp, string A, string end, unordered_set<string>st, vector<vector<string> >&sol)
{
    if (A == end)
    {
        sol.push_back(temp) ;
        return;
    }
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int tmp = A[i] - 'a';
            A[i] = j + 'a';
            if (st.find(A) != st.end())
            {
                temp.push_back(A);
//cout<<A<<" ";
                st.erase(A);
                dfs(temp, A, end, st, sol);
                temp.pop_back();
            }
            A[i] = tmp + 'a';
        }
    }
}

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    unordered_set<string>st;
    for (int i = 0; i < dict.size(); i++)
        st.insert(dict[i]);
    vector<string>temp;
    st.erase(start);
    temp.push_back(start);
    vector<vector<string> >ans, sol;
    dfs(temp, start, end, st , sol);
    int min_sz = INT_MAX;
    for (int i = 0; i < sol.size(); i++)
    {
        if (min_sz > sol[i].size())
            min_sz = sol[i].size();
    }
    for (int i = 0; i < sol.size(); i++)
        if (min_sz == sol[i].size())
            ans.push_back(sol[i]);
    return ans;
}

// https://www.interviewbit.com/problems/word-ladder-ii/