#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> num{0, 0, 0, 1, 1, 1};
    do {
        cout << "{";
        for (int i = 0; i < 6; ++i) {
            if (num[i])
                cout << i << ", ";
        }
        cout  << "}, " << endl;
    } while (next_permutation(num.begin(), num.end()));
    cout << endl;
    return 0;
}
