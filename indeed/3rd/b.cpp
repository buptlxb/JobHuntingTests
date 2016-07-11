#include <iostream>
#include <vector>

using namespace std;

int a, b, k;


int main(void)
{
    cin >> a >> b >> k;
    int t = 0;
    int i = a;
    double j = b + 0.5;
    bool flag = true;
    while (true) {
        if (i < j) {
            if (++t == k) {
                cout << "Takahashi" << endl;
                return 0;
            }
            i += a;
        } else {
            if (++t == k) {
                cout << "Aoki" << endl;
                return 0;
            }
            j += b;
        }
    }
    return 0;
}
