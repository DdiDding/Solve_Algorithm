#include <bits/stdc++.h>
using namespace std;

int pre_X[8] = { 0,1,1,1,0,-1,-1,-1 };
int pre_Y[8] = { 1,1,0,-1,-1,-1,0,1 };


int main()
{


	return 0;
}

/*
5 * 5 게임판

한글자에서 펜을 움직이면서 만나는 글자를 순서대로 나열해서 영단어 찾기
8방향 모두 움직이기 가능
건너뛸수 없음
다시 지나가기 가능

테스트케이스의 수 C

백트래킹
bool BS(찾는 단어)
{
	if(단어 완성이면 return true)
	if(단어 길이이상이면 return false)

	다음단어 8방향에서 찾아서 큐에 넣기

	큐 반복해서 BS호출
	{
		if (BS == true) return true;
	}

	return false;
}

*/