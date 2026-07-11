#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 20;

// Structure to store item details
struct Item
{
    float weight;
    float profit;
    float ratio;
};

// Comparator to sort items by profit/weight ratio
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

// Fractional Knapsack Function
void fractionalKnapsack(Item items[], int n, float capacity)
{
    float result[MAX] = {0};
    float totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= capacity)
        {
            result[i] = 1.0;
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {
            result[i] = capacity / items[i].weight;
            totalProfit += result[i] * items[i].profit;
            break;
        }
    }

    cout << "\nResult Vector:\n";

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << "\t";
    }

    cout << "\n\nMaximum Profit = " << totalProfit << endl;
}

int main()
{
    Item items[MAX];
    int n;
    float capacity;

    cout << "Enter the number of objects: ";
    cin >> n;

    cout << "\nEnter Weight and Profit of each object:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    cout << "\nEnter the capacity of the knapsack: ";
    cin >> capacity;

    // Sort according to Profit/Weight ratio
    sort(items, items + n, compare);

    fractionalKnapsack(items, n, capacity);

    return 0;
}