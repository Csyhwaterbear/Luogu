#include<bits/stdc++.h>
using namespace std;
struct student
{
	string name;
	int age;
	int score;
};
int main()
{
	
	int n;
	cin >> n;
	vector<student> Data(n);
	for (int i = 0; i < n; i++)
	{
		cin >> Data[i].name >> Data[i].age >> Data[i].score;
	}
	for (int i = 0; i < n; i++)
	{
		cout << Data[i].name << " " << Data[i].age + 1 << " " << min(600, int(Data[i].score * 1.2)) << endl;
	}
}
