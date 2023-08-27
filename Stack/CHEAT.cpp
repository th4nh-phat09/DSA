#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for (int i=l;i<=r;i++)
const int N = 1e5+5;
int n, x, a[N];
stack<int> st;
int solve()
 {
 //	cout<<st.top()<<" ";
	FOR(i,1,n) {
		if (a[i] > a[i-1])
		{
			for (x = x + 1; x < a[i]; x++) 
				st.push(x);
		} 
		else
		{
			if (! st.empty() && st.top() == a[i])
					 st.pop();
			else
				return puts("YES");
		}
		
	}
	return puts("NO");
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n;
	FOR(i,1,n) scanf("%d", &a[i]);
	solve();

	return 0;
}
