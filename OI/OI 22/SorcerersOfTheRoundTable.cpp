#include <stdio.h>

// Directed Graph Problem
// Hamiltonian Cycles

/*
N wizards take part in a council meeting. Every one of them is identified by the height of his hat.
Heights of the hats are different integers from 1 to n. (higher hat - more experienced sorcerer)
To keep the table aesthetic, heights of the hats worn by sorcerers sitting next to each other can't
be larger than p.
  Moreover, not all sorcerers like each other. If sorcerer a doesn't like sorcerer b, then sorcerer
b can't sit directly on the right side of sorcerer a. We assume that council chairman (with a hat
of height n) already chose his place by the round table. In how many ways the rest of them can
join him?

Input:
First line of the standard input contains three integers n, k and p.
(1 <= n <= 1000000, 0 <= k <= 100000, 0 <= p <= 3) separated by the single space.
n - number of sorcerers  ;  k - number of informations about their sympathies
p - biggest difference between the heights of their hats
Next k lines contains ordered pairs: i-th of them contain two integers a_i and b_i
(1 <= a_i,b_i <= n,a_i != b_i) separated by one space, meaning that sorcerer in the hat of height
a_i doesn't like the sorcerer in a hat of height b_i.
Every ordered pair of sorcerers may appear in the input only once.

Output:
Only line of the standard output should contain an integer - the remainder of division:
number of possibilities / 10^9+7

Example:
Input:          Output:
5 2 3           6
1 3
5 4

Explanation:
Sorcerers can sit by the table in six ways:
53124, 53142, 52143, 53412, 52314, 53214
 */

typedef struct Pair {
  int first;
  int second;
} Pair;

int main() {
  // int n, k, p;
  // scanf("%d %d %d", &n, &k, &p);
  // Pair *pairArr = new Pair[k];
  // for(int i = 0 ; i < k ; i++) {
    // scanf("%d %d", &pairArr[i].first, &pairArr[i].second);
    // printf("pairArr[%d]: %d %d\n", i,  pairArr[i].first, pairArr[i].second);
  // }
  printf("HEYah!\n");

  return 0;
}
