#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    cout << "\nDP Table:\n";
    cout << "   ";
    for (int w = 0; w <= W; w++) {
        cout << setw(4) << w;  
    }
    cout << "\n";
    for (int i = 0; i <= n; i++) {
        if (i == 0)
            cout << "0 ";  
        else
            cout << i << " "; 

        for (int w = 0; w <= W; w++) {
            cout << setw(4) << dp[i][w];  
        }
        cout << "\n";
    }
    return dp[n][W];
}
int main()
{
    int profit[] = {1,2,5,6 };
    int weight[] = {2,3,4,5};
    int W = 8;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << "Item\tWeight\tProfit\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << weight[i] << "\t" << profit[i] << "\n";
    }
    int maxProfit = knapSack(W, weight, profit, n);
    cout << "\nMaximum profit: " << maxProfit << endl;
    return 0;
}
