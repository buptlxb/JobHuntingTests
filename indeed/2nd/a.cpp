#include <iostream>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    for (string::size_type i = 0, iend = s.size(); i < iend; ++i) {
        char c = s[i];
        if (c == ',')
            cout << '\n';
        else
            cout << c;
    }
    cout << endl;
    return 0;
}
