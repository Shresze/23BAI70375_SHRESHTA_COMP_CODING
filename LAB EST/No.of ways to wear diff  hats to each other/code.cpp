class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        const int mod=1e9+7;

        vector<vector<int>> v(41);
        for (int i=0;i<n;i++) {
            for (int h:hats[i]) {
                v[h].push_back(i);
            }
        }

        vector<vector<int>> dp(41,vector<int>(1<<n,-1));

        function<int(int,int)> solve=[&](int hat, int mask) {
            if (mask==(1<<n)-1) return 1;
            if (hat>40) return 0;

            if (dp[hat][mask]!=-1)
                return dp[hat][mask];

            long long ways=solve(hat+1,mask);

            for (int p:v[hat]) {
                if ((mask & (1<<p))==0) {
                    ways+=solve(hat+1,mask | (1<<p));
                    ways%=mod;
                }
            }

            return dp[hat][mask]=ways;
        };

        return solve(1, 0);
    }
};
