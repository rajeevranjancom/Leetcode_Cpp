class Solution {
public:
int longestValidParentheses(string s) {
int l=s.size();
vectorv(l+1,0);

    for(int i=0;i<l;i++)
    {
        if(s[i]==')')
            v[i+1]=v[i]-1;
        else
            v[i+1]=v[i]+1;     
    }
    
    map<int,int>m;
    
    int mx=0;

    m[0]=0;
    
    for(int i=1;i<=l;i++)
    {
        if(m.find(v[i])==m.end())
        {
            m[v[i]]=i;
            continue;
        }
        if((v[i-1])==(v[i]-1))
        {
                m[v[i]]=i;    
        }
        else
        {
            mx=max(mx, i-m[v[i]]);
        }
    }
    
    
    return mx;
}
};

****************************

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), i = 0, ans = 0, k = 0;
        for(int j = 0; j < n; j++) {
            if(s[j] == '(')  k++;
            else if(s[j] == ')') {
                k--;
                if(k == 0)
                    ans = max(ans, j - i + 1);
            }
            if(k < 0) {
                k = 0;
                i = j + 1;
            }
        }
        k = 0, i = n - 1;
        for(int j = n - 1; j >= 0; j--) {
            if(s[j] == ')') {
                k++;
            }
            else if(s[j] == '(') {
                k--;
                if(k == 0)
                    ans = max(ans, i - j + 1);
            }
            if(k < 0) {
                k = 0;
                i = j - 1;
            }
        }
        return ans;
    }
};


