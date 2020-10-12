class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), sum = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 0; i < n; i++){
            if(i - 1 >= 0 && ratings[i - 1] < ratings[i]) left[i] = left[i - 1] + 1;
            else left[i] = 1;
            int j = n - 1 - i;
            if(j + 1 < n && ratings[j + 1] < ratings[j]) right[j] = right[j + 1] + 1;
            else right[j] = 1;
        }
        for(int i = 0; i < n; i++){
            sum += (left[i] > right[i]) ? left[i] : right[i];
        }
        return sum;
    }
};

*************************

    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        if(n < 2)   return n;
        int res = 0;
        vector<int> C(n, 1);
        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
                C[i] = C[i-1] + 1;
        }
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1] && C[i] <= C[i+1])
                C[i] = C[i+1] + 1;
        }
        for(int i=0; i<n; i++)
            res += C[i];
        return res;
    }


*********************

int candy(vector<int>& rat) 
{
	int sz = rat.size();
	if (sz < 2)
		return sz;
	vector<int> can(sz, 1);
	int i, sum = 0;
	for (i = 1; i < sz; ++i)
	{
		if (rat[i]>rat[i - 1])
			can[i] = can[i - 1] + 1;
	}
	for (i = sz - 1; i; --i)
	{
		sum += can[i];
		if (rat[i - 1] > rat[i])
			can[i - 1] = max(can[i - 1], can[i] + 1);
	}
	return sum + can[0];
}

