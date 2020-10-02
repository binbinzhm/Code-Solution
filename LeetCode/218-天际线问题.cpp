/*
扫描线，从左到右
只关注高度的变化
    当有点重合时怎么办（先加再减）
每一个轮廓的变化一定是楼的顶点

用multiset存高度，方便找最大高度和删除元素

*/
#include <vector>
#include <set>

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int> > returnBuilding;
        vector<pair<int, int>> p;
        multiset<int> m;

        for (int i = 0; i < buildings.size();i++) {
            p.push_back({buildings[i][0], -buildings[i][2]});
            p.push_back({buildings[i][1], buildings[i][2]});
        }

        sort(p.begin(), p.end());

        int max = 0;
        m.insert(0);
        for (int i = 0;i < p.size();i++) {
            if (p[i].second < 0) m.insert(-p[i].second);
            else m.erase(m.find(p[i].second));

            if ((*m.rbegin()) != max) {
                max = *m.rbegin();
                returnBuilding.push_back(vector<int> {p[i].first,max});
            }
        }


        return returnBuilding;
    }
};