# include <bits/stdc++.h>
using namespace std;
int main()
{
	int x, n, c;
	cin >> x >> n;
	c=(n/7)*5;
    
    	if(n%7 > (7-x) && x>6)
    		c+=n%7-1;
    	else if(n%7 > (7-x))
    		c+=n%7-2;
    	else
    		c+=n%7;
    
    	cout<<c*250;
	return 0;
}

