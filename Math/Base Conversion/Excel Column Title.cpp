string Solution::convertToTitle(int columnNumber)
{
	string columnTitle = "";

	while (columnNumber)
	{
		columnNumber--;
		char rightMost = (char) ((columnNumber % 26) + 'A');
		columnTitle = rightMost + columnTitle;
		columnNumber /= 26;
	}

	return columnTitle;
}


// https://www.interviewbit.com/problems/excel-column-title/