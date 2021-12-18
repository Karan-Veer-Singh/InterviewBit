vector<vector<int> > Solution::fourSum(vector<int> &A, int target)
{
    vector<vector<int>> ans;

    if (A.empty())
        return ans;

    int n = A.size();

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target2 = target - A[j] - A[i];
            int front = j + 1;
            int end = n - 1;

            while (front < end)
            {
                int sum2 = A[front] + A[end];

                if (sum2 == target2)
                {
                    vector<int> quad(4, 0);
                    quad[0] = A[i];
                    quad[1] = A[j];
                    quad[2] = A[front];
                    quad[3] = A[end];

                    ans.push_back(quad);

                    while (front < end && A[front] == quad[2])
                    {
                        front++;
                    }
                    while (front < end && A[end] == quad[3])
                    {
                        end--;
                    }
                }
                else if (sum2 < target2)
                {
                    front++;
                }
                else
                {
                    end--;
                }
            }

            while (j + 1 < n && A[j + 1] == A[j])
            {
                j++;
            }
        }

        while (i + 1 < n && A[i + 1] == A[i])
        {
            i++;
        }
    }

    return ans;

}

// https://www.interviewbit.com/problems/4-sum/