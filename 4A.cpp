#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int melon; cin >> melon;
	if (melon == 2 || melon & 0x1 == 0x1)
		puts("NO");
	else
		puts("YES");
	
	return 0;
}