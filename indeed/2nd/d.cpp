#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

double dfs(vector<double> &expect, int idx, vector<double> &probility)
{
    if (expect[idx] != -1)
        return expect[idx];
    expect[idx] = 0;
    double ps = 0;
    for (int i = 0; i < probility.size(); ++i) {
        if (idx & (1 << i))
            ps += probility[i];
        else
            expect[idx] += (dfs(expect, idx | (1 << i), probility) + 1) * probility[i];
    }
    expect[idx] = (expect[idx] + ps) / (1 - ps);
    return expect[idx];
}

double solve(vector<double> &probility)
{
    vector<double> expect(1<<probility.size(), -1);
    expect.back() = 0;
    return dfs(expect, 0, probility);
}

int main(void)
{
    int k;
    cin >> k;

    vector<int> ball(k);
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        cin >> ball[i];
        sum += ball[i];
    }

    vector<double> probility(k);
    for (int i = 0; i < k; ++i)
        probility[i] = 1.0 * ball[i] / sum;

    cout << fixed << setprecision(9);
    cout << solve(probility) << endl;
    return 0;
}
