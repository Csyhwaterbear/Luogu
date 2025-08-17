#include <bits/stdc++.h>

struct student
{
	std::string name;
	int I, II, III, Total;

	student(std::string n, int c, int m, int e): name(n), I(c), II(m), III(e)
	{
		Total = I + II + III;
	}
};

int main()
{
	int N;
	std::cin >> N;
	std::vector<student> students;
	for (int i = 0; i < N; i++)
	{
		std::string name;
		int c, m, e;
		std::cin >> name >> c >> m >> e;
		students.emplace_back(name, c, m, e);
	}
	// sort with lexicographical order
	std::sort(students.begin(), students.end(), [](const student &a, const student &b){return a.name < b.name;});

	std::vector<std::pair<std::string, std::string>> results;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			const student &s1 = students[i];
			const student &s2 = students[j];

			if (std::abs(s1.I - s2.I) <= 5 && std::abs(s1.II - s2.II) <= 5 && std::abs(s1.III - s2.III) <= 5 && std::abs(s1.Total - s2.Total) <= 10)
			{
				results.emplace_back(s1.name, s2.name);
			}
		}
	}

	for (const auto &pair : results)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
	}
	return 0;
}
