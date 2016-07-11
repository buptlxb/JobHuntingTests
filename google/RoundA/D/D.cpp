#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

#define M 1000000000
#define N 12
int A[N][M];
int C[N][M];
int K[N];
int L[N];

int k, l, m, n;

long long maxp = 0;

long long solve(long long power)
{
    if (m <= 0)
        return power;

}

int main(void)
{
    int count;
    cin >> count;
    for (int i = 1; i <= count; ++i) {
        cin >> m >> n;
        for (int j = 0; j < n; ++j) {
            cin >> K[j] >> L[j];
            for (int r = 0; r < K[j]; ++r) {
                cin >> A[j][r];
            }
            for (int r = 0; r < K[j]-1; ++r) {
                cin >> C[j][r];
            }
            C[j][K[j]-1] = M + 5;
        }
        cout << "Case #" << i << ": " << solve() << '\n';
    }
    cout << flush;
    return 0;
}
