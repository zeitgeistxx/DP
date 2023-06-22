#include<iostream>
using namespace std;


int dp[100][1000];

int CountSubsetSum(int a[], int s, int n){
    for (int i = 0; i < n + 1; i++) dp[i][0] = 1;
    for (int j = 1; j < s + 1; j++) dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < s + 1; j++){
            if(a[i - 1] <= j){
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}


int main(){
    int n;
    cout << "Enter array length -> ";
    cin >> n;

    int a[n];
    cout << "Enter array -> ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int s;
    cout << "Enter required sum -> ";
    cin >> s;

    cout << CountSubsetSum(a, s, n);
}