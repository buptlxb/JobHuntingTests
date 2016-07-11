#include <iostream>
#include <vector>

using namespace std;

#define N 6

int board[N][N];
int row_cnt[N] = {0, };
int col_cnt[N] = {0, };
int num = 0;
int place[][3] = {
    {3, 4, 5}, 
    {2, 4, 5}, 
    {2, 3, 5}, 
    {2, 3, 4}, 
    {1, 4, 5}, 
    {1, 3, 5}, 
    {1, 3, 4}, 
    {1, 2, 5}, 
    {1, 2, 4}, 
    {1, 2, 3}, 
    {0, 4, 5}, 
    {0, 3, 5}, 
    {0, 3, 4}, 
    {0, 2, 5}, 
    {0, 2, 4}, 
    {0, 2, 3}, 
    {0, 1, 5}, 
    {0, 1, 4}, 
    {0, 1, 3}, 
    {0, 1, 2}
};

unsigned long long dfs(int idx)
{
    if (idx == N)
        return 1;
    if (row_cnt[idx] == 3)
        return dfs(idx+1);
    unsigned long long ret = 0;
    for (int i = 0; i < 20; ++i) {
        int j;
        for (j = 0; j < 3; ++j) {
            if (board[idx][place[i][j]] == 0) {
                board[idx][place[i][j]] = 2;
                ++row_cnt[idx];
                ++col_cnt[place[i][j]];
                if (col_cnt[place[i][j]] > 3)
                    break;
            }
        }
        if (j == 3 && row_cnt[idx] == 3)
            ret += dfs(idx+1);
        for (j = 0; j < 3; ++j) {
            if (board[idx][place[i][j]] == 2) {
                board[idx][place[i][j]] = 0;
                --col_cnt[place[i][j]];
                --row_cnt[idx];
            }
        }
    }
    return ret;
}

unsigned long long solve()
{
    return dfs(0);
}

int main(void)
{
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        for (string::size_type j = 0, jend = s.size(); j < jend; ++j) {
            if (s[j] != '.') {
                board[i][j] = 1;
                ++row_cnt[i];
                ++col_cnt[j];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (row_cnt[i] > 3) {
            cout << 0 << endl;
            return 0;
        }
        num += row_cnt[i];
    }
    for (int i = 0; i < N; ++i) {
        if (col_cnt[i] > 3) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << solve() << endl;
    return 0;
}
