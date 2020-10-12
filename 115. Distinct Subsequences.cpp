class Solution {
public:
    int numDistinct(string s, string t) {
        
        long long n=s.length(),m=t.length(),i,j;
        
        vector<vector<long long>> dp(2, vector<long long> (n+1));
        
        for(i=0; i<=n; i++)
            dp[0][i]=1;
        
        for(i=1; i<=m; i++)
            for(j=0; j<=n; j++)
            {
                if(j==0)
                    dp[i%2][j]=0;
                
                else if(s[j-1]==t[i-1])
                    dp[i%2][j] = dp[i%2][j-1] + dp[(i-1)%2][j-1];
                else
                    dp[i%2][j] = dp[i%2][j-1];
            }
            
        
        // for(i=0; i<2; i++)
        // {
        //     for(j=0; j<=n; j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[m%2][n];
    }
};

*********************

class Solution {
public:
int numDistinct(string s, string t) {
int m=t.length(),n=s.length();
vector<vector> dp(m+1,vector(n+1,0));
for(int i=0;i<=m;i++){
dp[i][s.length()]=0;
}
for(int i=0;i<=n;i++){
dp[t.length()][i]=1;
}

    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s[j]==t[i]){
                dp[i][j]+=dp[i+1][j+1];
            }
            dp[i][j]+=dp[i][j+1];
        }
    }
    return dp[0][0];
}
};

***************

class Solution {
public:
    int numDistinct(const string& s, const string& t) {
        vector<vector<unsigned int>> dp(s.length()+1, vector<unsigned int>(t.length()+1, 0));
        
        for (int sLen = 0; sLen <= s.length(); ++sLen) {
            dp[sLen][0] = 1;
        }
        
        
        for (int sLen = 1; sLen <= s.length(); ++sLen) {
            for (int tLen = min(sLen, static_cast<int>(t.length())); tLen > 0; --tLen) {
                // Always add the case where you delete the current character from the source
                dp[sLen][tLen] += dp[sLen-1][tLen];
                
                // If the characters match between the source and target
                // we have found a case where we can choose to not delete the current source character 
                // Hence, add the results of this case to the dp
                if (s[sLen-1] == t[tLen-1]) {
                    dp[sLen][tLen] += dp[sLen-1][tLen-1];
                }
            }
        }
        
        return dp[s.length()][t.length()];
    }
    
    
