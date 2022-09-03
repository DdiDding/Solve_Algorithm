#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> A;
	int x;
	//그냥 찾으려는 x값이 해당하는 인덱스를 반환한다. 해도 되는데 왜 이렇게 어렵게 써놨냐하면 반복문의 내부 변수의 결과도 표현한 것이기 때문이다.
	//반환하려는 변수가 i라면 x는 A[i]와 같다  s가 A[i - 1]이 될거고, e가 A[i]가 된다.여기서 생각해보면 x = A[i]가 될수 밖에 없는데 A[i - 1]이 x보다 작기 때문이다.??
	

	//필수조건:오름차순 정렬이 되어야한다. - 이해
	//결과:A[i -1] < x <= A[i] 에서 i를 반환한다. (x의 인덱스를 반환한다는 말) 
	int lo = -1, hi = A.size();

	//이게 성립한다는 가정?
	//불변식1 : lo < hi - while이 false여도 성립하고 true여도 성립한다.
	//불변식2 : A[lo] < x <= A[hi]

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (A[mid] < x)
			lo = mid;
		if (x <= A[mid])
			hi = mid;
	}

	return 0;
}
