# include <iostream>
using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int Time = (c-a)*60 + (d-b);
	cout << Time / 60 << " " << Time % 60;
}
