// TEST: Knapsack 1-0 problem: knapsackProblem.hpp
//    int n_items = 5;
//    int capacity = 11;
//    int *values = new int[n_items];
//    int *weights = new int[n_items];
//    values[0] = 1; weights[0] = 1;
//    values[1] = 6; weights[1] = 2;
//    values[2] = 18; weights[2] = 5;
//    values[3] = 22; weights[3] = 6;
//    values[4] = 28; weights[4] = 7;
//    maxValueforKnapsack(capacity, n_items, values, weights);

#include "knapsack_problem.hpp"

using namespace std;

int main(int argc, const char *argv[]){
    int capacity;

    cout << "Enter capacity of the knapsack: ";
    cin >> capacity;
    cout << "Enter items - value & weight: "; // each item contains value and weight. enter like: 4 5 (enter)

    vector<int> values;
    vector<int> weights;

    int f,s;
    while(cin >> f && cin >> s){
        values.push_back(f);
        weights.push_back(s);
    }

    // Example below can be used

    // int capacity = 11; 
    // values[0] = 1; weights[0] = 1;
    // values[1] = 6; weights[1] = 2;
    // values[2] = 18; weights[2] = 5;
    // values[3] = 22; weights[3] = 6;
    // values[4] = 28; weights[4] = 7;

    /*
    RESULT:
       0 1 2 3 4 5 6 7 8 9 10 11
    0: 0 0 0 0 0 0 0 0 0 0 0 0
    1: 0 1 1 1 1 1 1 1 1 1 1 1
    2: 0 1 6 7 7 7 7 7 7 7 7 7
    3: 0 1 6 7 7 18 19 24 25 25 25 25
    4: 0 1 6 7 7 18 22 24 28 29 29 40
    5: 0 1 6 7 7 18 22 24 28 29 29 40
    */

    MaxValueforKnapsack(capacity, values.size(), values, weights);
}