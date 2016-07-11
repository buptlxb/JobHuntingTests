#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

#define R 50
#define C 50

int r, c, n;
char board[R][C];
bool visit[R][C];

int mem[1024];
int pos[10][2];

void dfs(int x, int y)
{
    visit[x][y] = true;
    if (board[x][y] == 'R' && y+1 < c && !visit[x][y+1])
        dfs(x, y+1);
    else if (board[x][y] == 'C' && x+1 < r && !visit[x+1][y])
        dfs(x+1, y);
}

double solve() {
    unsigned long long count = 0;
    for (int i = 0, iend = 1<<n; i < iend; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j))
                board[pos[j][0]][pos[j][1]] = 'C';
            else
                board[pos[j][0]][pos[j][1]] = 'R';
        }
        int cur = 0;
        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                if (visit[x][y])
                    continue;
                dfs(x, y);
                ++cur;
                ++count;
            }
        }
        memset(visit, false, sizeof(visit));
    }
    return 1.0 * count / (1 << n);
}

int main(void)
{
    cin >> r >> c;
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        for (int j = 0; j < c; ++j) {
            board[i][j] = s[j];
            if (s[j] == '?') {
                pos[n][0] = i;
                pos[n++][1] = j;
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << solve() << endl;
    return 0;
}
