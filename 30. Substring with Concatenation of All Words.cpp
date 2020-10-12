class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> freq;
        for(auto w: words){
            freq[w]++;
        }        
        
        int n = s.size(), total = words.size(), len = words[0].size(); 
        vector<int> answer;
        
        for(int i = 0; i < n - total * len + 1; i++){
            int j = i;
            unordered_map<string, int> stats = freq;
            int covered = 0;
            while(covered < total && j + len - 1 < n) {
                string word = s.substr(j, len);
                if(stats.find(word) != stats.end() && --stats[word] >= 0) {
                    covered++;
                    j += len;
                }else break;
            }
            if(covered == total) answer.push_back(i);
        }
        
        return answer;
    }
};

************************************

 vector<int> findSubstring(string s, vector<string>& words) {
        
        int wordsize = words[0].length();
        int len = s.length(); int size = words.size();
        vector<int>result;
        if(size <= 0 || len <= 0)
            return result;
        if(size*wordsize > len)
            return result;
        unordered_map<string,int>word;
        for(int i=0 ; i < size ; i++)
        {
            word[words[i]]++;
        }
        
        for(int i = 0 ; i < len-(wordsize*size)+1 ; i++)
        {
            unordered_map<string , int>visit;
            int j = 0;
            for( ; j<size ; j++)
            {
                string w = s.substr(i+j*wordsize , wordsize);
                if(word.find(w) != word.end())
                {
                    visit[w]++;
                   if(visit[w] > word[w])
                       break;
                }   
                else
                    break;
            }
            if(j == size)
                result.push_back(i);
        }
        return result;
  }
  
  
