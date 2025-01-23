# include <bits/stdc++.h>
using namespace std;
int main()
{
	string ISBN;
	int sum=0, j=1;
	char mod[12]="0123456789X";
	cin >> ISBN;
	for ( size_t i = 0; i < ISBN.length()-2; i++ )
	{
		if ( 48 <= int(ISBN[i]) and int(ISBN[i]) <= 57 )
		{
			sum += ( int(ISBN[i])  - 48 ) * j++;
		}
	}
	if(ISBN[12]==mod[sum % 11]){cout << "Right";}
	else{ISBN[12]=mod[sum % 11];cout << ISBN;}
	return 0;

}
