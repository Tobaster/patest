#include <iostream>
#include <string.h>

using namespace std;

void judge(const char* test, const int n)
{
    bool flag=true;
    int a=0, b=0, c=0;      //a为P前的A的数量，b为P到T之间的A的数量，c为T后A的数量——c=a*b
    int countp=0, countt=0; //记录P及T的数量
    int pp=0, pt=0;         //用于记录P的位置以及T的位置

    for (int i = 0; i < n; i++) {
        if (test[i] == 'A') continue;
        else if (test[i] == 'P') {
            countp++;
            pp = i;
        }
        else if (test[i] == 'T') { 
            countt++;
            pt = i;
        }
        else {                      //若出现非PAT字符，直接跳出，并报错
            flag = false;
            break;
        }
    }

    a = pp;
    b = pt - pp - 1;
    c = n - pt - 1;
    if (countp != 1 || countt != 1 || b == 0) flag = false;
    
    if (c != a*b || flag == false) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    int n;
    char test[100];
    
    cin >> n;   //n为需要判断的字数
    for (int i = 0; i < n; i++) {
        cin >> test;                //输入需要测试的字符串
        judge(test, strlen(test));  //调用函数判定该字符串是否符合要求
    }

    system("pause");
    return 0;
}