#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    int maxi = 0, maxj = -1, maxsum = -1;       //令maxj = -1, 解决全为负数，令maxsum为-1，解决最大值为0
    int thisi = 0, thisj = 0, thissum = 0;
    int N;
    // int *seq = new int[N];
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; i++) cin >> seq[i];

    for (int i = 0; i < N; i++) {
        thissum += seq[i];
        thisj = i;
        if (thissum > maxsum) {
            maxi = thisi;
            maxj = thisj;
            maxsum = thissum;
        }
        if (thissum < 0) {
            thisi = i+1;
            thisj = i+1;
            thissum = 0;
        }
    }
    if (maxj != -1)
        cout << maxsum << ' ' << seq[maxi] << ' ' << seq[maxj] << endl;
    else
        cout << 0 << ' ' << seq[0] << ' ' << seq[N-1] << endl;

    system("pause");
    return 0;
}