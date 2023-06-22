#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


// Initialize the matrix according to the given constraints, say n<=100, W<=1000
static int dp[101][1001];


struct Bag{
    int profit, weight;
};

int Knapsack(Bag b[], int W, int n){
    if(n == 0 || W == 0) 
        return 0;
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    if(b[n - 1].weight <= W){
        return dp[n][W] = max(b[n - 1].profit + Knapsack(b, W - b[n - 1].weight, n - 1), Knapsack(b, W, n - 1));
    }
    else if(b[n - 1].weight > W){
        return dp[n][W] = Knapsack(b, W, n - 1);
    }
}


int main(){
    memset(dp, -1, sizeof(dp));

    int n, W;
    cout << "Enter no. of Bags and Knapsack capacity -> ";
    cin >> n >> W;

    cout << "\n\n";

    Bag b[n];
    for (int i = 0; i < n; i++){
        cout << "Bag no. " << i + 1 << ":" << endl;
        cout << "Profit -> ";
        cin >> b[i].profit;
        cout << "Weight -> ";
        cin >> b[i].weight;
    }

    cout << "\nMax Profit = " << Knapsack(b, W, n);
}