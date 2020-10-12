class Solution {
private:
    string binary(int i) {
        string b;
        while (i) {
            b += to_string(i%2);
            i /= 2;
        }
        reverse(b.begin(), b.end());
        return b;
    }
    char x_or(char a, char b) {
        return a != b ? '1' : '0';
    }
    string to_gray(string bin) {
        string g; 
        g += bin[0];
        for (int i=1; i<bin.length(); ++i)
            g = g + x_or(bin[i-1], bin[i]);
        return g;
    }
    int to_int(string g) {
        int integer = 0, i=g.length()-1, p = 0;
        while (i >= 0)
            integer = integer + (1<<p++) * (g[i--]-'0');
        return integer;
    }
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        for (int i=1; i<(1<<n); ++i) {
            string bin = binary(i);
            string gray = to_gray(bin);
            ans.push_back(to_int(gray));
        }
        return ans;
    }
};

***********************************

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        if(n==0)
            return v;
        v.push_back(1);
        if(n==1)
            return v;
        int i=0,j=1;
        while(i<pow(2,n-1)){
            i=pow(2,j);
            j++;
            for(int k=i-1;k>=0;k--){
                v.push_back(v[k]+i);
            }
        }
        return v;
    }
};

*************************************
