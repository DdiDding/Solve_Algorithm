#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	for (const auto & data : a)
	{
		if (data % 2 == 0)
		{
			cout << "even"<<endl;
		}
		else
		{
			cout << "odd" << endl;
		}
	}
	
	return 0;
}
