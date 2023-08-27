#include<bits/stdc++.h>
using namespace std;
string x;
void solve()
{
	stack<int> s;
	map<char,int> mp;
	mp['H']=1;
	mp['O']=16;
	mp['C']=12;
	mp['(']=-1;
	for(int i=0;i<x.length();i++)
		{
			if(x[i]=='H'||x[i]=='O'||x[i]=='C'||x[i]=='(')
				s.push(mp[x[i]]);
			if(x[i]==')')
				{
					int k=0;
					while(s.top()!=-1)
						{
							k+=s.top();
							s.pop();
						}
					s.pop();
					s.push(k);
				}
			if(x[i]>='2'&&x[i]<='9')
				s.top()*=int(x[i])-'0';
		}
	long long res=0;
	while(!s.empty())
		{
			res+=s.top();
			s.pop();
		}
	cout<<res;
}
int main()
{
	freopen("BAI.inp","r",stdin);
	cin>>x;
	solve();
}
