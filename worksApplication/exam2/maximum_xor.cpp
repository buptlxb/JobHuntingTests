#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct TrieNode {
    int val;
    TrieNode *children[2];
    TrieNode () : val(0) {}
} *root = new TrieNode;

void add(long long x)
{
    TrieNode *cur = root;
    for (int i = 63; i >= 0; --i) {
        bool idx = x & (1 << i);
        if (!cur->children[idx])
            cur->children[idx] = new TrieNode;
        cur = cur->children[idx];
    }
    cur->val = x;
}

long long query(long long x)
{
    TrieNode *cur = root;
    for (int i = 63; i >= 0; --i) {
        bool idx = x & (1 << i);
        if (cur->children[1 - idx])
            cur = cur->children[1 - idx];
        else
            cur = cur->children[idx];
    }
    return x ^ cur->val;
}

long long solve(vector<long long> &nums)
{
    add(0);
    long long ret = numeric_limits<long long>::min();
    long long cur_xor = 0, all_xor = 0;
    for (auto x : nums)
        all_xor ^= x;
    for (auto x : nums) {
        cur_xor ^= x;
        add(cur_xor);
        ret = max(ret, query(cur_xor^all_xor));
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (long long i = 0; i < n; ++i)
        cin >> nums[i];
    cout << solve(nums) << endl;
    return 0;
}
