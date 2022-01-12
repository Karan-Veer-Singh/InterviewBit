int Solution::gcd(int A, int B)
{
	if (B == 0)  return A;
	return gcd(B, A % B);
}


// https://www.interviewbit.com/problems/greatest-common-divisor/