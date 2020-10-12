class Solution {
public:
    void decomposeIpAddresses(string s, vector<string>&snippets, vector<string>&ipAddresses, int buildPointer){

        // goal or base case
        if(buildPointer == s.size() && snippets.size() == 4){
            cout<<"a"<<endl;
            ipAddresses.push_back(snippets[0] + '.'+ snippets[1] + '.' + snippets[2] + '.' + snippets[3]);
            return ;
        }
        else if(buildPointer == s.size() || snippets.size() == 4){
            return ;
        }


        for(int len = 1; len <= 3 && buildPointer + len <= s.size(); len++){
            // choice
            string snippet = s.substr(buildPointer, len);

            // constraint
            if( (stoi(snippet) > 255) || (snippet.size() > 1 && snippet[0] == '0') )break;

            // Choose , explore , Unchoose
            snippets.push_back(snippet);
            decomposeIpAddresses(s, snippets, ipAddresses, buildPointer+len);
            snippets.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ipAddresses;
        vector<string>snippets;
        decomposeIpAddresses(s, snippets, ipAddresses, 0);
        return ipAddresses;
    }
};

************************

vector<string> restoreIpAddresses(string s) {
        if (s.empty()) return {};
        vector<string> res;
        dfs("", 1, 0, res, s);
        return res;
    }

    void dfs(string prefix, int step, int start, vector<string> &res, string &str) {
        //step mean next find segment step, prefix is 4 more dots than str.size()
        if (step == 5 && prefix.size() - str.size() == 4) {
            prefix.pop_back();
            res.push_back(prefix);
            return;
        }
        if (step > 5) {
            return;
        }
        for(int i = 1; i < 4; i++) {
            int end = start + i;
			//handle '001' case
            if(end > str.size() || (i > 1 && str[start] == '0')) continue;
            string segment = str.substr(start, i);
            int num = stoi(segment);
            if(num < 0 || num > 255) {
                continue;
            }
            dfs(prefix + segment + ".", step+1, end, res, str);
        }
    }
