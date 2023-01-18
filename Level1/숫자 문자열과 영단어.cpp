#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

const string num[10] ={"zero","one","two","three","four","five","six","seven","eight","nine"};

typedef pair<int,int> pii;
vector<pii> v;

int solution(string s) {
    int answer = 0;

    //문자만 변환하는 곳
    int i, j;
    size_t t;
    for(i = 0; i < 10; ++i)
    {
        t = 0;
        do
        {
            t = s.find(num[i], t);
            if (t != string::npos)
            {
                v.push_back({t++, i});
            }
            else break;
        }while(true);
    }
    //숫자만 변환하는 곳
    for (i = 0; i < s.size(); ++i)
    {
        //숫자가 영어보다 아스키코드가 작음
        if(s[i] <= '9')
        {
           v.push_back({i,s[i] - '0'});
        }
    }
    sort(v.begin(), v.end());

    for(const auto & d: v)
    {
        answer = answer * 10 + d.second;
    }

    return answer;
}