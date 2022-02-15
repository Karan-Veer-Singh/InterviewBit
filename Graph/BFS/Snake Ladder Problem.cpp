int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
	unordered_map<int, int> ladder;

	for (auto i : A)
		ladder[i[0]] = i[1];

	for (auto i : B)
		ladder[i[0]] = i[1];

	queue<int> q;
	vector<bool> vis(101, false);

	q.push(1);
	vis[1] = true;

	int diceCount = 0;

	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			int curr = q.front();
			q.pop();

			if (curr == 100)
				return diceCount;

			for (int i = 1; i <= 6; i++)
			{
				int next = curr + i;

				if (next > 100)  break;

				if (vis[next] == false)
				{
					if (ladder.find(next) != ladder.end())
					{
						q.push(ladder[next]);
						vis[ladder[next]] = true;
					}
					else
					{
						q.push(next);
						vis[next] = true;
					}
				}
			}
		}

		diceCount++;
	}

	return -1;
}


// https://www.interviewbit.com/problems/snake-ladder-problem/