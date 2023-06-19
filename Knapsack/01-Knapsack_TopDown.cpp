#include<iostream>
#include<algorithm>
using namespace std;



struct Bag{
    int profit, weight;
};


int main(){
    int n, W;
    cout << "Enter no. of Bags and Kanpsack capacity -> ";
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