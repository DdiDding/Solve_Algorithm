#include <iostream>
#include <string>
using namespace std;
int main()
{
myGoTo:
	int a;
	scanf("%d", &a);
	
	if (a == 0) return 0 ;

	cout << a << endl;
	goto myGoTo;

	return 0;
}
