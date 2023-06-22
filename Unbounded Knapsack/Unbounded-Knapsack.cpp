#include <iostream>
#include <algorithm>
using namespace std;


int t[101][1001];

int Knapsack(int wt[], int val[], int W, int n){
    for (int i = 0; i < n + 1; i++) t[i][0] = 0;
    for (int i = 0; i < W + 1; i++) t[0][i] = 0;

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < W + 1; j++){
            if (wt[i - 1] <= j){
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    int n, W;
    cout << "Enter no. of items and Knapsack capacity -> ";
    cin >> n >> W;

    cout << "\n\n";

    int wt[n], val[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Bag no. " << i + 1 << ":" << endl;
        cout << "Profit -> ";
        cin >> val[i];
        cout << "Weight -> ";
        cin >> wt[i];
    }

    cout << "\nMax Profit = " << Knapsack(wt, val, W, n);
}