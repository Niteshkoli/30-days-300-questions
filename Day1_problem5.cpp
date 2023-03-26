class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor) {
        int n = coor.size();
        for(int i=0;i<n-2;i++){
            int first = coor[i][0]*(coor[i+1][1]-coor[i+2][1]);
            int second = coor[i+1][0]*(coor[i+2][1]-coor[i][1]);
            int third = coor[i+2][0]*(coor[i][1]-coor[i+1][1]);
            if(first+second+third !=0) return false;
        }
        return true;
    }
};
