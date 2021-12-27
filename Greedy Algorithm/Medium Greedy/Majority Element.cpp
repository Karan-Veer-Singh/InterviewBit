int Solution::majorityElement(const vector<int> &A)
{
    int count = 0;
    int element = 0;

    for (int num : A)
    {
        if (count == 0)
            element = num;

        if (num == element)
            count++;
        else
            count--;
    }

    return element;
}


// https://www.interviewbit.com/problems/majority-element/