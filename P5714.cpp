#include<iostream>
using namespace std;
int main(){
	double m,h,temp;
	cin>>m>>h;
	temp=m/(h*h);
	if(temp<18.5)cout<<"Underweight";
	else if(temp>=18.5&&temp<24)cout<<"Normal";
	else if(temp>=24)cout<<temp<<endl<<"Overweight";
	return 0;
}
