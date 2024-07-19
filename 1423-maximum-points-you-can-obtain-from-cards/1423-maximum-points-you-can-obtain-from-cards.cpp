class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        // TC - O(2 * k), SC - O(1)
        int leftSum = 0,rightSum = 0,maxSum = 0;
        for(int i=0;i < k;i++) leftSum += cardPoints[i];
        maxSum = leftSum;
        if(n == k) return maxSum;
        int rightIndex = n-1;
        for(int i=k-1;i >= 0;i--){ 
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightIndex];
            rightIndex--;
            maxSum = max(maxSum,leftSum+rightSum);
        }
        return maxSum;
        // approach 
        // take all k ele. from left(i.e. k), zero from right (i.e. 0)
        // k-1,1 
        // k-2,2
        // k-3,3 
        // .
        // .
        // 0,k
    }
}; 