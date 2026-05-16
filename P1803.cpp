#include<bits/stdc++.h>
using namespace std;

int main()
{
        ios::sync_with_stdio(false); cin.tie(nullptr);
	int n;
        if(!(cin >> n)) return 0;
	struct Item { int a; int b;};
	vector<Item> list(n);
	for (int i = 0; i < n; i++)
	{
                cin >> list[i].a >> list[i].b;
        }
        sort(list.begin(), list.end(), [](const Item &x, const Item &y){
                if (x.b != y.b) return x.b < y.b;
                return x.a < y.a;
        });
        int ans = 0;
        int last_end = INT_MIN;
        for (const auto &it : list)
        {
                if (it.a >= last_end)
                {
                        ans++;
                        last_end = it.b;
                }
        }
        cout << ans << endl;
	return 0;
}
