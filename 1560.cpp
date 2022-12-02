#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	string n; cin >> n;

	//1.Check One & Zero
	if (n == "0" || n == "1")
	{
		cout << n;
		return 0;
	}

	//2. Calculate n + n
	string ret;
	bool plus = false;
	while (0 < n.size())
	{
		int a = n.back() - '0';
		n.pop_back();

		a = plus ? a + a + 1 : a + a;
		plus = 9 < a ? true : false;

		ret += to_string(a % 10);
	}
	if (plus == true) ret += '1';

	//3. And then ret minus 2
	int k = 0;
	while (true)
	{
		if (k == 0) ret.at(k) -= 2;
		else ret.at(k) -= 1;

		//양수면
		if ('0' <= ret.at(k)) break;

		//음수일 때
		ret.at(k) += 10;
		++k;
	}

	//3. Print
	if (ret.back() != '0') cout << ret.back();
	for (int i = ret.size() - 2; -1 < i; --i)
	{
		cout << ret.at(i);
	}
	return 0;
}


//#include <stdio.h>
//#include <string.h>
//
//using namespace std;
//
//int l;
//char a[100];
//
//int main() {
//	int i;
//	scanf("%s", &a);
//	l = strlen(a);
//	//0 ~ 2까지는 값이 똑같다.
//	if (l == 1 && a[0] < '3') printf("%s", a);
//	//그 나머지 부분
//	else
//	{
//		//문자열의 zero based 사이즈 구함
//		l--;
//
//		//문자열의 처음부터 끝까지 반복하며 정수화 함.
//		for (i = 0; i <= l; i++)
//		{
//			a[i] -= '0';
//		}
//
//		//※1을 빼는 이유는 밑에서 *2를 해주기 위해서임.
//		//문자열의 마지막 수에서 1을 뺀다.
//		a[l]--;
//		//size값 복사
//		i = l;
//
//		//뒤에서부터 처음까지 양수가 나올때까지 탐색한다.
//		while (a[i] < 0)
//		{
//			//음수이기에 앞의 자리에서 10을 빌려오는것.
//			a[i] += 10;
//			//탐색자리수를 먼저 땡겨주고, 빌려준 자리를 정산한다.
//			a[--i]--;
//		}
//
//		//처음부터 끝까지 돌며 *2를 해준다.
//		for (i = 0; i <= l; i++)
//		{
//			a[i] *= 2;
//		}
//
//		//*2를 한 결과에서 다음 자리 수에게 올려줄 수가 있으면 계산해준다.
//		//중요한건 index 1까지만 계산한다.
//		for (i = l; i >= 1; i--)
//		{
//			if (10 <= a[i])
//			{
//				a[i] -= 10;
//				a[i - 1]++;
//			}
//		}
//
//		//결과 출력
//		//정수형으로 출력하기 때문에 위에서 마지막자리가 추가되도 가능했던것이다.
//		for (i = 0; i <= l; i++)printf("%d", a[i]);
//	}
//}