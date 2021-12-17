int Solution::colorful(int A)
{
    string s = to_string(A);
    unordered_map<long long, bool> m;

    for (long long i = 0; i < s.size(); i++)
    {
        long long mul = 1;
        for (long long j = i; j < s.size(); j++)
        {
            mul *= (long long)(s[j] - '0');
            if (m.find(mul) != m.end())
                return 0;

            m[mul] = true;
        }
    }
    return 1;
}


// https://www.interviewbit.com/problems/colorful-number/