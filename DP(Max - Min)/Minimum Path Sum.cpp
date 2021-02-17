class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        const int MAXn = 207, n = grid.size(), m = grid[0].size();
        cout << n << " " << m << '\n';
        vector<vector<int>> dp(MAXn, vector<int> (MAXn));
        //base case 
        dp[0][0] = grid[0][0];
        cout << dp[0][0] << '\n';
        //from top and left so [i][j-1],[i-1][j] respectively 
        
        
        for(int i=1; i < m; ++i) {
            dp[0][i] = (grid[0][i] + dp[0][i-1]);
        }        
        
        for(int j=1; j < n; ++j) {
            dp[j][0] = (grid[j][0] + dp[j-1][0]);
        }
        
        for(int i=1;i<n;++i) {
            for(int j=1;j<m;++j) {
                dp[i][j] = (grid[i][j] + min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        for(int i{};i<n ;++i) {
            for(int j{};j<m;++j) {
                cout << grid[i][j] << ":" << dp[i][j] << " \n"[j+1 == m];
            }
        }
        return dp[n-1][m-1];   
        // return 0;
    }

};
