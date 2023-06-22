#include <iostream>
#include <algorithm>
using namespace std;

struct Bag
{
    int profit, weight;
};

int t[101][1001]; // t[n+1][W+1]

int Knapsack(Bag b[], int W, int n)
{
    // Initialization
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for (int i = 0; i < W + 1; i++)
        t[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (b[i - 1].weight <= j)
            {
                t[i][j] = max(b[i - 1].profit + t[i - 1][j - b[i - 1].weight], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    int n, W;
    cout << "Enter no. of Bags and Kanpsack capacity -> ";
    cin >> n >> W;

    cout << "\n\n";

    Bag b[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Bag no. " << i + 1 << ":" << endl;
        cout << "Profit -> ";
        cin >> b[i].profit;
        cout << "Weight -> ";
        cin >> b[i].weight;
    }

    cout << "\nMax Profit = " << Knapsack(b, W, n);
}