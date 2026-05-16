#include<bits/stdc++.h>
using namespace std;

int main()
{
        ios::sync_with_stdio(false); cin.tie(nullptr);
	int n;
        if (!(cin >> n)) return 0;
        vector<int> list(n);
        for (int i = 0; i < n; cin >> list[i++]);

        vector<pair<int, int>> a;
        a.reserve(n);
        for (int i = 0; i < n; i++) a.emplace_back(list[i], i + 1);
        sort(a.begin(), a.end(), [](const auto &x, const auto &y){
                if (x.first != y.first) return x.first < y.first;
                return x.second < y.second;
                        });

        for (int i = 0; i < n; i++)
        {
                if (i) cout << ' ';
                cout << a[i].second;
        }
        cout << '\n';

        int prefix = 0;
        double sum = 0.0;
        for (int i = 0; i < n; i++)
        {
                sum += prefix;
                prefix += a[i].first;
        }
        cout.setf(ios::fixed);
        cout << setprecision(2) << sum / n << '\n';
	return 0;
}
