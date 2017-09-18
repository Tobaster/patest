#include <iostream>
using namespace std;

int countStep(int n)
{
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else if (n%2 == 0) return 1+countStep(n/2);
    else return 1+countStep((3*n+1)/2);
}
int main()
{
    int n;
    cin >> n;       // 输入需要计算的n值
    int step = countStep(n);
    cout << step;
    
    system("pause");
    return 0;
}