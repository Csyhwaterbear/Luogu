#include<bits/stdc++.h>
using namespace std;

int main()
{
        ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, T;
        if(!(cin >> n >> T)) return 0;
	struct Item { int m; int v; double density; };
	vector<Item> gold(n);
	for (int i = 0; i < n; i++)
	{
                int m, v;
                cin >> m >> v;
                gold[i] = {m, v, double(v) / m};
	}
        sort(gold.begin(), gold.end(), [](const Item &x, const Item &y){
                return x.density > y.density;
        });
	double ans = 0;
        int cap = T;
        for (const auto &it : gold)
        {
                if (cap == 0) break;
                if (it.m <= cap)
                {
                        ans += it.v;
                        cap -= it.m;
                }
                else
                {
                        ans += it.density * cap;
                        cap = 0;
                }
        }
        cout.setf(ios::fixed);
        cout << setprecision(2) << ans << endl;
	return 0;
}
