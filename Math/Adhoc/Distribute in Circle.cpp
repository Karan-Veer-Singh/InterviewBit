int Solution::solve(int A, int B, int C)
{
	return ((A % B) + ((C % B) - 1)) % B;
}


// https://www.interviewbit.com/problems/distribute-in-circle/