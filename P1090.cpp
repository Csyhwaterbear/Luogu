#include<bits/stdc++.h>
using namespace std;
#define int long long
#undef int
int main()
{
        ios::sync_with_stdio(false); cin.tie(nullptr);
	int n;
        if (!(cin >> n)) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
                int x;
                cin >> x;
                pq.push(x);
        }

        int ans = 0;
        while (pq.size() > 1)
        {
                int a = pq.top(); pq.pop();
                int b = pq.top(); pq.pop();
                int c = a + b;
                ans += c;
                pq.push(c);
        }
        cout << ans << endl;
	return 0;
}
