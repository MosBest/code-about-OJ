#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

typedef struct 
{
    int x;
    int y;
    int step;
} path;

char map[MAXN][MAXN];
int n, m, t;

path Path;  //  ��������λ��

int ans = INF;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

//  ����Ƿ���Ե���
bool check(int x, int y)
{
    if (map[x][y] == 'X' || map[x][y] == 'E' || map[x][y] == 'D')
    {
        return false;
    }
    return true;
}

//  Ԥ����
char getCharValue(char otype, char type)
{
    if ((type == 'D' && otype == 'e') || (type == 'E' && otype == 'd'))
    {
        return 'b';
    }
    return type == 'D' ? 'd' : 'e';
}

//  Ԥ�������ܿ���D��λ����Ϊd������E��λ����Ϊe���ܿ������ߵ���Ϊb
void setMap(int x, int y, char type)
{
    int i;
    for (i = x + 1; i < n && check(i, y); ++i)
    {
        map[i][y] = getCharValue(map[i][y], type);
    }
    for (i = x - 1; i >= 0 && check(i, y); --i)
    {
        map[i][y] = getCharValue(map[i][y], type);
    }
    for (i = y + 1; i < m && check(x, i); ++i)
    {
        map[x][i] = getCharValue(map[x][i], type);
    }
    for (i = y - 1; i >= 0 && check(x, i); --i)
    {
        map[x][i] = getCharValue(map[x][i], type);
    }
}

//  ���߽�
bool isLegal(path p)
{
    if (p.x >= 0 && p.y >= 0 && p.x < n && p.y < m)
    {
        return true;
    }
    return false;
}

int bfs_(path startp, char type)
{
    queue<path> Qu;
    bool vis[MAXN][MAXN];
    path ptop, ptmp;
    memset (vis, false, sizeof(vis));
    vis[startp.x][startp.y] = true;
    Qu.push(startp);

    while (!Qu.empty())
    {
        ptop = Qu.front();
        Qu.pop();
        if ((type == 'd' && map[ptop.x][ptop.y] == 'e') || (type == 'e' && map[ptop.x][ptop.y] == 'd'))
        {
            return ptop.step;
        }
        for (int i = 0; i < 4; ++i)
        {
            ptmp.x = ptop.x + dir[i][0];
            ptmp.y = ptop.y + dir[i][1];
            ptmp.step = ptop.step + 1;
            if (isLegal(ptmp) && check(ptmp.x, ptmp.y) && !vis[ptmp.x][ptmp.y] && ptmp.step < ans)
            {
                vis[ptmp.x][ptmp.y] = true;
                Qu.push(ptmp);
            }
        }
    }
    return t + 1;
}

void bfs()
{
    queue<path> Qu;
    path ptop, ptmp;
    bool visited[MAXN][MAXN];
    ans = INF;
    memset(visited, false, sizeof(visited));
    Qu.push(Path);
    visited[Path.x][Path.y] = true;

    while (!Qu.empty())
    {
        ptop = Qu.front();
        Qu.pop();
        if (map[ptop.x][ptop.y] == 'b')
        {
            ans = min(ans, ptop.step);
        }
        else if (map[ptop.x][ptop.y] == 'e' || map[ptop.x][ptop.y] == 'd')
        {
            //  �ҵ�һ���ˣ����õڶ���bfsѰ�ҵڶ�����
            int tmp = bfs_(ptop, map[ptop.x][ptop.y]);
            ans = min (ans, tmp);
        }
        for (int i = 0; i < 4; ++i)
        {
            ptmp.x = ptop.x + dir[i][0];
            ptmp.y = ptop.y + dir[i][1];
            ptmp.step = ptop.step + 1;
            if (isLegal(ptmp) && check(ptmp.x, ptmp.y) && !visited[ptmp.x][ptmp.y] && ptmp.step < ans)
            {
                visited[ptmp.x][ptmp.y] = true;
                Qu.push(ptmp);
            }
        }
    }
    if (ans <= t)
    {
        printf ("%d\n", ans);
    }
    else
    {
        printf ("-1\n");
    }
}


int main()
{
    int Case = 1;
    while (~scanf("%d%d%d", &n, &m, &t))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf ("%s", map[i]);
            for (int j = 0; j < m; ++j)
            {
                if (map[i][j] == 'S')
                {
                    Path.x = i, Path.y = j, Path.step = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (map[i][j] == 'E')
                {
                    setMap(i, j, map[i][j]);
                }
                else if (map[i][j] == 'D')
                {
                    setMap(i, j, map[i][j]);
                }
            }
        }
        
        for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				printf("%c ",map[i][j]);
			}
			printf("\n");
		}	
        
        printf ("Case %d:\n", Case++);
        bfs();
    }
    return 0;
}
