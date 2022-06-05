#include<iostream>
#include<string>
#include <sstream>
#include <cctype>
#include <vector>
#include <stdlib.h>

using namespace std;


void main()
{
#include <cctype>
//isdigit(char)의 반환 값이 0이면 문자이고 아니면 숫자임
//문자 하나하나씩 판별해가는방식
string str = "1233BVBBA";

for (int i = 0; i < str.length(); ++i)
{
	if (isdigit(str[i]) == 0) cout << "문자임";
	else cout << "숫자임";
}
	
	return;
}