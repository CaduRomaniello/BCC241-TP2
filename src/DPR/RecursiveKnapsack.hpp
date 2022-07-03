#ifndef RECURSIVE_KNAPSACK_HPP
#define RECURSIVE_KNAPSACK_HPP

#include "../Problem/Problem.hpp"

using namespace std;

class RecursiveKnapsack {
   private:
    int weight;           // Backpack current weight
    int value;            // Backpack monetary value
    int itemsInSolution;  // Number of items in solution
    vector<int> items;    // Binary array representing each item. 1  means it is part of the solution.
                          // The position means the item index.

    int** memo;  // Memoization matrix. Row = item, Col = weight

   public:
    RecursiveKnapsack(int nitems, int weight);
    ~RecursiveKnapsack();

    /**
     * For a given instance, solve the Knapsack problem recursively using memoization.
     * @param instance is the instance data.
     */
    void solve(const Problem* instance);

    /**
     * For a given instance, display the solution for the Knapsack problem.
     * @param instance is the instance data.
     *
     * @ignore
     * In order to print, it traverse the memo matrix using the following steps:
     * 1 - Starting in the last cell of the matrix.
     * 2 - Check if the value is the same as the row above. If it is, the item is not part of the solution.
     * 3 - If the value is different, the item is part of the solution. The next cell to be verified will be the one
     *     in the row above and the column that matches the weight after taking away the item's weight from the current
     *     total weight.
     * 4 - Go back to 2.
     */
    void printSolution(const Problem* instance);

   private:
    int _solve(const Problem* instance, int nItems, int currentCapacity);
};

#endif