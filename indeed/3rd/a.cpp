#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string s, t;
    cin >> s >> t;

    if (s.size() != t.size())
        cout << "Impossible" << endl;

    bool flag = false;
    for (char x = 'a'; x <= 'z'; ++x) {
        for (char y = 'a'; y <= 'z'; ++y) {
            string tmp1 = s;
            string tmp2 = t;
            for (int j = 0; j < s.size(); ++j) {
                if (tmp1[j] == x)
                    tmp1[j] = y;
                if (tmp2[j] == x)
                    tmp2[j] = y;
            }
            if (tmp1 == tmp2) {
                flag = true;
                break;
            }
        }
    }
    cout << (flag ? "Possible" : "Impossible") << endl;
    return 0;
}
