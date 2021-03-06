string keypad[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solve(string input, string output, int i, int j, vector<string> &ans)
{
    if (i == input.size())
        return ans.push_back(output);

    int digit = input[i] - '0';

    for (int k = 0; keypad[digit][k]; k++)
    {
        output.push_back(keypad[digit][k]);
        solve(input, output, i + 1, j + 1, ans);
        output.pop_back();
    }
}

vector<string> Solution::letterCombinations(string digits)
{
    if (digits.size() == 0)
        return {};

    string output;
    vector<string> ans;

    solve(digits, output, 0, 0, ans);

    return ans;
}

// https://www.interviewbit.com/problems/letter-phone/