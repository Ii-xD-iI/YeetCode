class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int depth = triangle.size(), leaf = triangle[depth-1].size();
        vector<vector<int>> tree = triangle;//dp table
        

        if(depth==1){return triangle[0][0];}
        depth-=2;//base 0ed
        leaf--;//starting off from leaf-1 
        cout << depth << ' ' << leaf << '\n';
        for(int layer = depth; layer>=0; --layer) {
            for(int period{};period<leaf; ++period){
                tree[layer][period] += min(tree [layer+1] [period], tree [layer+1] [period+1]);
            }
            leaf--;
        }
        for(int i {};i<tree.size();++i){
            for(int j {};j<tree[i].size();++j){
                cout << tree[i][j] << " \n"[j+1 == tree[i].size()];
            }
        }
        //can move from [i] of the row j to [i] and [i+1] of the row j+1
        //bottom up wuld be :hmmmm:
        /*
            from leaf to root
            actually from leaf-1 to root 
            tree[depth][i] += min(tree[depth+1][i], tree[depth+1][i+1]); 
        */
        
        return tree[0][0];//root
    }
};
