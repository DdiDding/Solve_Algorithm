#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> v(122 - 97 + 2 ,-1);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string S; cin >> S;

	int i = 0;
	for (const char & data : S)
	{
		if (v[(int)data - 97] == -1)
		{
			v[(int)data - 97] = i;
		}
		++i;
	}

	for (int i = 97; i <= 122; ++i)
	{
		cout << v[i - 97] << " ";
	}
	return 0;
}

#include <cstdio>
int main() 
{
	int a[26] = { 0 }, i = 1, c; 
	
	for (; (c = getchar() - 97) != -87; i++)
	{
		a[c] ? 1 : a[c] = i;
	}
	
	for (int b : a)
	{
		printf("%d ", --b);
	}
}