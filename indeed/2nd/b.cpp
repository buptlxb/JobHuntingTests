#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums)
{
    int ret = 0;
    vector<bool> visit(nums.size());
    for (int i = 1; i < nums.size(); ++i) {
        if (visit[i])
            continue;
        visit[i] = true;
        int j = nums[i];
        while (j != i) {
            visit[j] = true;
            j = nums[j];
        }
        ++ret;
    }
    return ret;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    cout << solve(nums) << endl;
    return 0;
}
