#include<iostream>
#include <algorithm>
using namespace std;

bool dp[100][100];

bool SubsetSum(int a[], int s, int n){
    for (int i = 0; i < n + 1; i++) dp[i][0] = true;
    for (int j = 1; j < s + 1; j++) dp[0][j] = false;

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < s + 1; j++){
            if(a[i - 1] <= j){
                dp[i][j] = dp[i - 1][j - a[i - 1]] or dp[i - 1][j];
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

    int ans = SubsetSum(a, s, n);
    if(ans) cout << "True" << endl;
    else cout << "False" << endl;
}