bool isPossible(vector<int> &C, int painters, long long int time)
{
    int paintersCount = 0;
    long long int timeUsed = 0;

    for (int i = 0; i < C.size(); i++)
    {
        if (timeUsed + (long long)C[i] > time)
        {
            paintersCount++;
            timeUsed = (long long)C[i];
        }
        else
        {
            timeUsed += (long long)C[i];
        }
    }

    return paintersCount < painters ? true : false;
}

int Solution::paint(int A, int B, vector<int> &C)
{
    long long int low = C[0];
    long long int high = 0;

    for (int i = 0; i < C.size(); i++)
    {
        high += (long long)C[i];
        low = max(low, (long long)C[i]);
    }

    long long int ans;
    while (low <= high)
    {
        long long int mid = (long long) (low + high) >> 1;

        if (isPossible(C, A, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    ans = (ans * B) % 10000003;

    return ans;
}


// https://www.interviewbit.com/problems/painters-partition-problem/