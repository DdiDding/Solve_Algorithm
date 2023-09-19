//문제 해석
/*
그 날, 많은 남자들이 포럼의 아바타에 아름다운 여자 사진을 이용했다.
그 사진은 언뜻 보기에 성별에 대해 말하기 꽤 어렵다.

작년, hero가 포럼에서 예쁜이와 근사한 채팅을 나누었다.
그 후, 그들은 자주 대화했고 결국 온라인 커플이 되었다.

하지만 어제, 그는 그녀를 현실에서 보러갔는데 그녀는 실제로 남성이였다!
hero는 아주 슬펐고 다시 사랑하기 힘든상태가 되었다.
그래서 그는 그들의 닉네임을 통해 그들의 성별을 알아볼 수 있는 방법을 생각해냈습니다.

이것은 그의 방법입니다.
	만약 한 유저의 닉네임의 고유 문자가 홀수라면, 남자입니다.
	아니면 여자입니다.

당신에게 유저의 닉네임을 나타내는 String이 주어집니다,
hero의 방법을 사용해 hero를 도와 이 유저들의 성별을 밝혀주세요


Input	:첫 줄에 공백없는 String이 들어있습니다.(영어 소문자로만 이루어짐)
		 글자 수는 100자 이하 입니다.
Output	:여자일 경우 "CHAT WITH HER!", 남자일 경우 "IGNORE HIM!" 을 출력하세요
*/

//첫 번째 풀이
/*
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	//1. Get Input & Initializing value
	int chars[30]; memset(chars, 0, sizeof(chars));
	string s; cin >> s;
	int num = 0;
	
	//2. Calculate number of distinct character
	for (char& temp : s)
	{
		if (chars[temp - 'a'] == false)
		{
			chars[temp - 'a'] = true;
			++num;
		}
	}

	//3. Get result
	cout << (num & 0x1 ? "IGNORE HIM!" : "CHAT WITH HER!");
	return 0;
}
*/

//두 번째 풀이
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s; cin >> s;

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	cout << (s.size() & 1 ? "IGNORE HIM!" : "CHAT WITH HER!");
}
*/
