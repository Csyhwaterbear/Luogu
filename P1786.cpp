#include<bits/stdc++.h>
using namespace std;
struct Person {
	string name, title;
	int value, level, id;
};
int rank_level(string s) {
	if (s == "BangZhu")
		return 7;
	else if (s == "FuBangZhu")
		return 6;
	else if (s == "HuFa")
		return 5;
	else if (s == "ZhangLao")
		return 4;
	else if (s == "TangZhu")
		return 3;
	else if (s == "JingYing")
		return 2;
	else 
		return 1;
}
bool cmp1(const Person& a, const Person& b) {
	if (a.value != b.value) return a.value > b.value;
	return a.id < b.id;
}
bool cmp2(const Person& a, const Person& b) {
	if (rank_level(a.title) != rank_level(b.title))
		return rank_level(a.title) > rank_level(b.title);
	if (a.level != b.level)
		return a.level > b.level;
	return a.id < b.id;
}
int main()
{
	int n;
	cin >> n;
	vector<Person> all;
	vector<Person> others;
	for (int i = 0; i < n; i++) {
		Person p;
		cin >> p.name >> p.title >> p.value >> p.level;
		p.id = i;
		all.push_back(p);
		if (p.title != "BangZhu" && p.title != "FuBangZhu")
		{
			others.push_back(p);
		}
	}
	sort(others.begin(), others.end(), cmp1);
	for(size_t i = 0; i < others.size(); i++) {
		if (i < 2) others[i].title = "HuFa";
		else if (i < 6) others[i].title = "ZhangLao";
		else if (i < 13) others[i].title = "TangZhu";
		else if (i < 38) others[i].title = "JingYing";
		else others[i].title = "BangZhong";
	}
	for (auto &p : others) {
		all[p.id].title = p.title;
	}
	sort(all.begin(), all.end(), cmp2);
	for (auto const &p: all)
	{
		cout << p.name << " " << p.title << " " << p.level << endl;
	}
	return 0;
}
