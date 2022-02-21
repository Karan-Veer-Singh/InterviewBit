class cell
{
public:
    int x, y;

    cell() {}

    cell(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool isValid(int x, int y, int n, int m)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
        return true;

    return false;
}

int Solution::knight(int n, int m, int sourceX, int sourceY, int destX, int destY)
{
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));

    queue<cell> q;
    q.push(cell(sourceX, sourceY));
    vis[sourceX][sourceY] = true;

    cell t;
    int x, y;
    int dist = 0;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            t = q.front();
            q.pop();

            if (t.x == destX && t.y == destY)
                return dist;

            for (int i = 0; i < 8; i++)
            {
                x = t.x + dx[i];
                y = t.y + dy[i];

                if (isValid(x, y, n, m) && vis[x][y] == false)
                {
                    q.push(cell(x, y));
                    vis[x][y] = true;
                }
            }
        }
        dist++;
    }

    return -1;
}


// https://www.interviewbit.com/problems/knight-on-chess-board/