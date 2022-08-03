# Introduction

## Key to solving a dp problem efficienly is finding a way to break the problem into subproblems such that
1. The original problem can be solved relatively easily once solutions to the sub-problems are available, and
2. These subproblems solutions are cached.

## Common mistakes made when applying DP:
* Trying to think of the recursive case by splitting the problem into two equal halves, (aka quicksort) i.e. solve the subproblems for subarrays A[0: floor(n / 2)] and A[floor(n / 2) + 1: n] and combine the results. As, these two subproblems are not sufficient to solve the original problem.
* Make sure that combining solutions to the subproblems does yield a solution to the original problem. E.g. if the longest path without repeated cities from City 1 to City2 passess through City 3, then the subpaths from City1 to City3 and City3 to City 2 may not be individually longest paths without repeated cities.

## Tips:
* Consider using DP whenever you have to make choices to arrive at the solution, specifically, when the solution relates to subproblems
* In addition to optimization, DP is also applicable to counting and decision problems - any problem wher you can express a solution recursively in terms of the same computation on smaller instances
* Although conceptually DP involves recursion, often for efficiency the cache is built 'bottom-up' ie iteratively
* To save space, cache space may be recycled once it is known that a set of entries will not be looked up again
* Sometimes, recursion may out-perform a bottom-up DP solution e.g. when the solution is found early or subproblems can be pruned through bounding.


## Questions
1. Count the number of score combinations
safety -> 2
field goal -> 3
touchdown -> 7
combinations of [2, 3, 7] point plays can make up a final score.
E.g For 12
2 * 6
3 * 2 + 2 * 3
2 * 1 + 3 * 1 + 7 * 1
3 * 4
Input: final score and scores for individual plays
Returns: The number of combinations of plays that result in the final score.
f(n) = combinations of plays that result in score n

f(0) = 0, f(1) = 0 as smallest in this array is 2
f(2) = 1
f(3) = 1
f(4) = [2 + 2] = 1
f(5) = [2 + 3, 3 + 2] = 2
f(6) = [2 * 3, 3 * 2] = 2
f(7) = [7] = 1
f(8) = [2 * 4, 3 * 2 + 2, 2 * 3 + 2] = 3
f(9) = [7 + 2, 3 * 3, 2 + 7] = 3

f(n) = f(n - 2) + f(n - 3)