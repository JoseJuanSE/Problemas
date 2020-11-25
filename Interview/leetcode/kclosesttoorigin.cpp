//Problem:  K Closest Points to Origin
//link: https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    struct tri{
      int d;  
      vector<int> a;
      const bool operator<(const tri &a)const{
          return d<a.d;
      }
    };
    int distance(int a,int b){
        return a*a+b*b;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<tri> v(points.size());
        for(int i=0;i<points.size();i++){
            v[i].d=distance(points[i][0],points[i][1]);
            v[i].a=points[i];
        }
        priority_queue<tri>pq;
        for(int i=0;i<points.size();i++){
            pq.push(v[i]);
            if(pq.size()>K)pq.pop();
        }
        vector<vector<int> > ans;
        while(!pq.empty()){
            ans.push_back(pq.top().a);
            pq.pop();
        }
        return ans;
    }
};