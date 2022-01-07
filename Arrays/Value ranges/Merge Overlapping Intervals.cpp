/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare(Interval a, Interval b)
{
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A)
{
    vector<Interval> ans;

    if (A.size() == 0)
        return ans;

    sort(A.begin(), A.end(), compare);

    Interval temp = A[0];

    for (auto curr : A)
    {
        if (curr.start <= temp.end)
            temp.end = max(curr.end, temp.end);
        else
        {
            ans.push_back(temp);
            temp = curr;
        }
    }

    ans.push_back(temp);
    return ans;
}


// https://www.interviewbit.com/problems/merge-overlapping-intervals/