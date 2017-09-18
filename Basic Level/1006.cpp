#include <iostream>
#include <string>
using namespace std;
// 让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（n<10），
// 换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，
// 因为它有2个“百”、3个“十”、以及个位的4。

int main()
{
    int realNu;                 //用于记录值本身
    string formatNu = "";     //用于记录改变个时候的值
    int Number;                 //用于存储每次取余的值
    int i = 0;                  //用于记录位数
    cin >> realNu;

    while (realNu != 0) {
        Number = realNu % 10;
        if (i == 0)
            while (Number != 0){
                char ch = Number + '0';
                formatNu = ch + formatNu;
                Number--;
            }
        else if (i == 1)  
            while (Number != 0){
                formatNu = 'S' + formatNu;
                Number--;
            }
        else
            while (Number != 0){
                formatNu = 'B' + formatNu;
                Number--;
            }
        realNu = realNu / 10;
        i++;
    }

    cout << formatNu << endl;
    system("pause");
    return 0;
} 