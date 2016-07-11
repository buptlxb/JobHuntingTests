#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

#define R 50
#define C 50

int board[R][C];
int rain[R][C];
int r, c;
int hight;

typedef vector<int>::size_type sz_t;
int trap(vector<int>& height) {
    stack<int> lefts;
    int ret = 0;
    for (sz_t i = 0, iend = height.size(); i < iend; ++i) {
        if (lefts.empty() || height[lefts.top()] > height[i])
            lefts.push(i);
        else if (lefts.size() == 1) {
            lefts.pop();
            lefts.push(i);
        } else {
            int base = lefts.top();
            do {
                lefts.pop();
                ret += (min(height[i], height[lefts.top()]) - height[base]) * (i - lefts.top() - 1);
                base = lefts.top();
            } while (lefts.size() > 1 && height[i] >= height[base]);
            if (height[i] >= height[base])
                lefts.pop();
            lefts.push(i);
        }
    }
    return ret;
}

int solve()
{
    int ret = 0;
    int row = 0, col = 0;
    for (int x = 1; x < r-1; ++x) {
        vector<int> height(board[x], board[x]+c);
        row += trap(height);
    }
    for (int y = 1; y < c-1; ++y) {
        vector<int> height(r);
        for (int x = 0; x < r; ++x)
            height[x] = board[x][y];
        col += trap(height);
    }
    cout << row << " " << col << endl;

    return min(row, col);
}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        //memset(visit, false, sizeof(visit));
        cin >> r >> c;
        hight = 0;
        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                cin >> board[x][y];
                rain[x][y] = board[x][y];
                hight = max(hight, board[x][y]);
            }
        }
        cout << "Case #" << i << ": " << solve() << '\n';
    }
    cout << flush;
    return 0;
}
