int Solution::solve(int A) {
	if (A < 9)   return A;

	int p = 1;

	while (A) {
		int d = A % 10;
		p *= d;
		A /= 10;
	}

	return p;
}


// https://www.interviewbit.com/problems/product-of-digits/