# include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	cin >> a[1] >> a[2] >> a[3];
	sort(a+1, a+4);
	if ( a[1] + a[2] <= a[3] ){ cout << "Not triangle" << endl; }
    else
    {
        if ( a[1] * a[1] + a[2] * a[2] == a[3]*a[3] ){ cout << "Right triangle" << endl; }
	if ( a[1] * a[1] + a[2] * a[2] > a[3]*a[3] ){ cout << "Acute triangle" << endl;  }
	if ( a[1] * a[1] + a[2] * a[2] < a[3]*a[3] ){ cout << "Obtuse triangle" << endl;  }
        if ( a[1] == a[2] || a[2] == a[3] || a[3] == a[1] ){ cout << "Isosceles triangle" << endl;  }
	if ( a[1] == a[2] && a[2] == a[3] ){ cout << "Equilateral triangle" << endl;  }
    }
	
	return 0;
}