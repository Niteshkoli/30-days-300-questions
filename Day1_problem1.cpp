class Solution {
public:
    int maxLen = -1;

    void getCycle(vector<int>& edges,int si,vector<bool>& vis,vector<int>&  store){
        if(si==-1) return;
        if(vis[si]){
            int count = -1;
            for(int i=0;i<store.size();i++){
                if(store[i]==si){
                    count = i;
                    break;
                }
            }
            if(count == -1) return;
            int size = store.size()- count;
            maxLen = max(maxLen,size);
            return;
        }
        vis[si] = true;
        store.push_back(si);
        getCycle(edges,edges[si],vis,store);
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vector<int> store;
            getCycle(edges,i,vis,store);
        }
        return maxLen;
    }
};
