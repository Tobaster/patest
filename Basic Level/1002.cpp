#include <iostream>
using namespace std;

string cp[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int Sum(string Str)
{
    int sum = 0;
    for (int i=0; i < Str.length(); i++){
        sum += int(Str[i] - '0');
    }
    return sum;
}

string reverse(int sum){
    string S = "";
    while (sum != 0){
        S += char(sum %10);
        sum /= 10;
    }
    return S;
}
// 将sum输出
void output(string S)
{
    cout << cp[int(S[S.length()-1])];
    for (int i=S.length()-2; i >= 0; i--)
        cout << " " << cp[int(S[i])];
}

int main()
{
    string Str;
    cin >> Str;
    int sum = Sum(Str);
    string S = reverse(sum);
    output(S);

    system("pause");
    return 0;
}