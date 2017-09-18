// 非二叉树（家族谱）求叶节点，求每一层中无子节点的节点。
#include <cstdlib>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int level[110];
int N, M;
map<int, vector<int> > mv;

int main(void)
{
    int id, id1, k;
    cin >> N >> M;

    while (M--) {
        cin >> id >> k;
        while (k--) {
            cin >> id1;
            mv[id].push_back(id1);
        }
    }
    
    vector<int> v1, v2, result;
    v1.push_back(1);
    while (!v1.empty()) {
        int leaf = 0;
        for (int i = 0; i < v1.size(); i++) {   // 遍历每一层的所有节点，判断是否为叶节点
            if (mv.count(v1[i]) == 0)           // 若是：leaf++;
                leaf++;
            else {                              // 若否，将其所有子节点压入v2中
                for (int j = 0; j < mv[v1[i]].size(); j++)
                    v2.push_back(mv[v1[i]][j]);
            }
        }
        result.push_back(leaf);
        swap(v1, v2);
        v2.clear();
    }
    for (int i = 0; i < result.size(); i++) {
        if (i != 0)
            cout << ' ';
        cout << result[i];
    }

    system("pause");
    return 0;
}