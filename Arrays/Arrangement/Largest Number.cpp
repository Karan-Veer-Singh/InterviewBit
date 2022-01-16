bool compare(string a, string b)
{
    return ( (a + b) > (b + a) );
}

string Solution::largestNumber(const vector<int> &A)
{
    string ans = "";
    int zero = 0;
    vector<string> s;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            zero++;

        s.push_back( to_string(A[i]) );
    }

    if (zero == A.size())
        return "0";

    sort(s.begin(), s.end(), compare);

    for (string x : s)
        ans += x;

    return ans;

}


// https://www.interviewbit.com/problems/largest-number/