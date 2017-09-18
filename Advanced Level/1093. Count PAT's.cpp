// 数一个字符串中PAT的数量，如果数量太多，则对1000000007取余。
#include <cstdlib>
// #include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    long int countP = 0, countPA = 0, countPAT = 0;
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'P')          // 新出现一个P，P的计数加一
            countP++;
        else if (str[i] == 'A')     //新出现一个A，PA组合的计数加P
            countPA += countP;
        else if (str[i] == 'T')     //新出现一个T，PAT的组合计数加PA
            countPAT += countPA;
    }
    cout << countPAT%1000000007 << endl;
      
    system("pause");
    return 0;
}