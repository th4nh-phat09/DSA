#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a=100;
	int **p;
	int *k=&a;
	p=&k;
	cout<<&k<<" "<<&a<<"\n";
	cout<<p<<" "<<*p<<" "<<**p;
	return 0;
}
