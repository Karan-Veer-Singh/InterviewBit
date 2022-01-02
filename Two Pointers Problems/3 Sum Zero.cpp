vector<vector<int> > Solution::threeSum(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    long long int n = A.size();

    for (long long int i = 0; i < n - 2; i++)
    {
        if ( i == 0 || (i > 0 && A[i] != A[i - 1]) )
        {
            long long int low = i + 1;
            long long int high = n - 1;
            long long int target;

            if (A[i] == 2147483647)
                target = -2147483647;
            else if (A[i] == -2147483648)
                target = 2147483648;
            else
                target = 0 - A[i];

            while (low < high)
            {
                long long int sum = (long long int)A[low] + (long long int)A[high];

                if (sum == target)
                {
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[low]);
                    temp.push_back(A[high]);

                    ans.push_back(temp);

                    while (low < high && A[low + 1] == A[low]) {
                        low++;
                    }

                    while (low < high && A[high - 1] == A[high])  {
                        high--;
                    }

                    low++;
                    high--;

                }
                else if (sum < target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
    }

    return ans;
}


// https://www.interviewbit.com/problems/3-sum-zero/