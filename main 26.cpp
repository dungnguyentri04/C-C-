#include "bits/stdc++.h"
using namespace std;

int n, m;
int a[1001][1001];
int d[1001][1001]; // Lưu chi phí để đến từng ô
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    d[i][j] = a[i][j];

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        for (int k = 0; k < 3; k++)
        {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 0)
            {
                if (d[i1][j1] >= d[top.first][top.second] + a[i1][j1])
                {
                    d[i1][j1] = d[top.first][top.second] + a[i1][j1];
                    q.push({i1, j1});
                }
            }
        }
    }
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            d[i][j] = INT_MAX; // Khởi tạo chi phí ban đầu là vô cùng
        }
    }
    bfs(1, 1);
    cout << d[n][m];
}

int main()
{
    input();
    return 0;
}
