#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool dp[100][100];

void SubsetSum(int a[], int s, int n){
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
}


int MinimumDifference(int a[], int n){
    int range = 0;
    for (int i = 0; i < n; i++) range += a[i];

    SubsetSum(a, range, n);

    vector<int> v;

    for (int i = 1; i <= range / 2; i++){
        if(dp[n][i]) v.push_back(i);
    }

    int minDiff = INT_MAX;
    for (int a: v){
        minDiff = min(minDiff, range - 2 * a);
    }
    return minDiff;
}


int main(){
    int n;
    cout << "Enter array length -> ";
    cin >> n;

    int a[n];
    cout << "Enter array -> ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << MinimumDifference(a, n) << endl;
}