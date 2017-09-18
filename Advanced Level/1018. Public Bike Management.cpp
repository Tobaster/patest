//这个题目13号再做
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

// e表示边（用以表示图）；weight表示单车（和最优单车量的差值）；dist表示从总站点到达该店的最短距离
int e[510][510], weight[510], dist[510];
bool visit[510];                    // visit中存储表示第i个节点是否被查看过
vector<int> pre[510];               // pre中存储该点左右可能的前驱元
vector<int> path, tmppath;          // path——最终路径，tmppath——当前求解的路径
const int INF = 999999;
int minNeed = INF, minBack = INF;   // 最少需要送出以及最少需要回收量

void dfs(int v);                    //深度优先搜索——求出所有最短路径中需要送出车辆最少，回收车辆最少的路径
void dijkstra(int n);                //求出所有可能的最短路径

int main(void)
{
    int cmax, n, sp, m;
    int a, b, c;

    fill(e[0], e[0]+510*510, INF);
    fill(dist, dist+510, INF);
    fill(visit, visit+510, false);

    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        weight[i] -= cmax / 2;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }

    dijkstra(n);
    dfs(sp);
    
    cout << minNeed << ' ' << 0;
    for (int i = path.size()-2; i >= 0; i--)
        cout << "->" << path[i];
    cout << ' ' << minBack << endl;

    system("pause");
    return 0;
}

void dijkstra(int n)
{
    dist[0] = 0;        // 标记处总站点

    for (int i = 0; i <= n; i++) {
        int sid = -1, mindist = INF;
        for (int j = 0; j <= n; j++) {  //找出未被查看且距离最小的站点
            if (visit[j] == false && dist[j] < mindist) {
                sid = j;
                mindist = dist[j];
            }
        }
        if (sid == -1)    break;          // j=-1意味着所有节点都被遍历过了
        visit[sid] = true;
        for (int v = 0; v <= n; v++) {  // 更新与v相连的每一个节点
            if (visit[v] == false && e[sid][v] != INF) {
                if (dist[sid] + e[sid][v] < dist[v]) {      // 如果从sid到v的距离小于，则v的前驱元只能是sid
                    dist[v] = dist[sid] + e[sid][v];
                    pre[v].clear();
                    pre[v].push_back(sid);
                }
                else if (dist[sid] + e[sid][v] == dist[v]) {
                    pre[v].push_back(sid);
                }
            }
        }
    }
}
// v即需要深度遍历的点，直到0（总站点结束）
void dfs(int v)
{
    if (v == 0) {
        int need = 0, back = 0;
        tmppath.push_back(v);
    
        for (int i = tmppath.size()-2; i >= 0; i--) {   //依据当前路径求需要回收以及送出的车
            int id = tmppath[i];
            if (weight[id] > 0) 
                back += weight[id];
            else {
                if (back >= -weight[id])
                    back += weight[id];
                else {
                    need += (0 - weight[id]) - back;
                    back = 0;
                }
            }
        }
        if (need < minNeed || (need == minNeed && back < minBack)) {
            minNeed = need;
            minBack = back;
            path = tmppath;
        }
        tmppath.pop_back();
    }
    // v!=0，即还没有到达总站——使用迭代将路径存放在tmppath中
    tmppath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    tmppath.pop_back();
}