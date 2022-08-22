#include <iostream>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(0), cin.tie(0);
	long t; cin >> t;
	while (t--) 
	{
		long n; cin >> n;
		//방향 입력 받고
		string s; cin >> s;
		bool left(true), right(true);
		//가능방개수
		long cnt(0);

		//방개수만큼 반복
		for (long p = 0; p < n; p++) 
		{
			//양옆중에 양방향이있으면 가능
			if ((s[(n + p - 1) % n] == '-') || (s[p % n] == '-'))
			{
				++cnt; 
			}

			//한방향으로 모두가능한지 체크
			if (s[p] == '<') { right = false; }
			else if (s[p] == '>') { left = false; }
		}

		//어느 한방향으로 모두가능하면 방개수만큼 가능
		if (left || right) { cnt = n; }
		cout << cnt << endl;
	}
	return 0;
}

//
////양쪽에 양방향이 있는지 확인
//int returnRoom = 0;
//if (1)
//{
//
//}
//else
//{
//	//4. n(방개수)만큼 반복
//	char sign; int temp;
//	for (int i = 0; i < N; ++i)
//	{
//		temp = i;
//		//왼쪽으로 가본다.
//		do
//		{
//			sign = belt[i];
//			++temp;
//			if (temp % N != 0)
//			{
//				returnRoom++;
//				break;
//			}
//		} while (sign != '<');
//		//오른쪽으로 가본다.
//	}
//}