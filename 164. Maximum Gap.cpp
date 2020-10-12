class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int maxGap = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            if((nums[i+1] - nums[i]) > maxGap){
                maxGap = (nums[i+1] - nums[i]);
            }
        }
        
        return maxGap;
    }
};

********************

class Solution {
public:
    //bucket sort
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len < 2){
            return 0;
        }
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for(int i : nums){
            minValue = min(minValue, i);
            maxValue = max(maxValue, i);
        }
        int gap = ceil(double((maxValue - minValue))/ (len - 1));
        vector<int> minGaps(len - 1, INT_MAX);// the minmum value of each bucket
        vector<int> maxGaps(len - 1, INT_MIN);
        for(int i : nums){ // fill in the bucket
            if(i == minValue || i == maxValue){
                continue;
            }
            int gapidx = (i - minValue) / gap;
            minGaps[gapidx] = min(minGaps[gapidx], i);
            maxGaps[gapidx] = max(maxGaps[gapidx], i);
        }
        int pre = minValue;
        int ans = INT_MIN;
        for(int i = 0; i < len - 1; ++i){
            if(minGaps[i] == INT_MAX && maxGaps[i] == INT_MIN){
                continue;
            }
            ans = max(ans, minGaps[i] - pre);
            pre = maxGaps[i];
        }
        ans = max(ans, maxValue - pre);
        return ans;
    }
};

*************************class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        auto lu = minmax_element(nums.begin(), nums.end());
        int l = *lu.first, u = *lu.second;
        int gap = max((u - l) / (n - 1), 1);
        int m = (u - l) / gap + 1;
        vector<int> bucketsMin(m, INT_MAX);
        vector<int> bucketsMax(m, INT_MIN);
        for (int num : nums) {
            int k = (num - l) / gap;
            if (num < bucketsMin[k]) bucketsMin[k] = num;
            if (num > bucketsMax[k]) bucketsMax[k] = num;
        }
        int i = 0, j; 
        gap = bucketsMax[0] - bucketsMin[0];
        while (i < m) {
            j = i + 1;
            while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN)
                j++;
            if (j == m) break;
            gap = max(gap, bucketsMin[j] - bucketsMax[i]);
            i = j;
        }
        return gap;
    }
};


