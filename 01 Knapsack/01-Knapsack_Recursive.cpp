#include<iostream>
#include<algorithm>
using namespace std;


struct Bag{
    int profit, weight;
};

int Knapsack(Bag b[], int W, int n){
    if(n == 0 || W == 0) 
        return 0;
    if(b[n - 1].weight <= W){
        return max(b[n - 1].profit + Knapsack(b, W - b[n - 1].weight, n - 1), Knapsack(b, W, n - 1));
    }
    else if(b[n - 1].weight > W){
        return Knapsack(b, W, n - 1);
    }
}


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