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

int main(int argc, const char *argv[]){
	int n_items = 5;
    int capacity = 11;
    std::vector<int> values(n_items);
    std::vector<int> weights(n_items);
    values[0] = 1; weights[0] = 1;
    values[1] = 6; weights[1] = 2;
    values[2] = 18; weights[2] = 5;
    values[3] = 22; weights[3] = 6;
    values[4] = 28; weights[4] = 7;
    MaxValueforKnapsack(capacity, n_items, values, weights);
}