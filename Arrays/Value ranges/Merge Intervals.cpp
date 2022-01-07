/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{
    vector<Interval> ans;

    for (auto curr : intervals)
    {
        if (curr.end < newInterval.start)
        {
            ans.push_back(curr);
        }
        else if (newInterval.end < curr.start)
        {
            ans.push_back(newInterval);
            newInterval = curr;
        }
        else
        {
            newInterval.start = min(newInterval.start, curr.start);
            newInterval.end = max(newInterval.end, curr.end);
        }
    }

    ans.push_back(newInterval);
    return ans;
}


// Time Complexity:  O(N).
// Space Complexity: O(1).

// https://www.interviewbit.com/problems/merge-intervals/