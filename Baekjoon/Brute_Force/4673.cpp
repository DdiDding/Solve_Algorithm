#include <stdio.h>
#define MAX_INDEX 10001

//true�� selfNum�̴�.
bool isInitNum[MAX_INDEX] = { 0 };

int main()
{
	//make selfNumber
	for(int i = 1; i < MAX_INDEX; ++i)
	{
		
		isInitNum[i + (i / 1000) + (i % 1000 / 100) + (i % 100 / 10) + (i % 10)] = true;
	}
	//Print num
	for(int i = 1; i < MAX_INDEX; ++i)
	{
		if (isInitNum[i] == false)
			printf("%d\n", i);
	}

}

//Shot�ڵ� ������ �̫���
//int a[9999], d;main() { for (;d < 9999;a[d + d % 10 + d / 10 % 10 + d / 100 % 10 + d / 1000]++)if (!a[++d])std::cout << d << '\n'; }������