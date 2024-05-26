// Sliding Window
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, leftSum = 0, rightSum = 0;

        for(int i = 0; i < k; i++){
            leftSum+=cardPoints[i];
        }

        int i = k-1;
        int j = cardPoints.size()-1;
        ans = leftSum;
        
        while(i >= 0){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[j];
            ans = max(ans, leftSum + rightSum);
            i--;
            j--;
        }

        return ans;
    }
};


// Recursion
class Solution {
private:
    int maxScoreHelper(vector<int>& cardPoints, int k, int i, int j){
        if(k == 0) return 0;

        if(i == j) return cardPoints[i];

        int start = cardPoints[i] + maxScoreHelper(cardPoints, k-1, i+1, j);
        int end = cardPoints[j] + maxScoreHelper(cardPoints, k-1, i, j-1);

        return max(start, end);
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        return maxScoreHelper(cardPoints, k, 0, cardPoints.size() - 1);
    }
};

// Memoization
