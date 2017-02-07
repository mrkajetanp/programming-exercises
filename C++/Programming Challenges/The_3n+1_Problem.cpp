/*
Algorithm generates a sequence of numbers. Start with an integer n. If n is even, divide by 2.
If n is odd, multiply by 3 and add 1. Repeat the process with the new value of n.
Terminate when n == 1.
For example, the following sequence of numbers will be generated for n == 22
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

It is conjectured (but not yet proven) that this algorithm will terminate at n == 1 for every int n.
Still, the conjecture holds for all integers up to at least 1,000,000.
  For an input n, the cycle-length of n is the number of numbers generated up to and including 1.
In the example above, the cycle-length of 22 is 16. Given any two numbers i and j, you are to
determine the maximum cycle length over all numbers between i and j, including both endpoints.

Input:
  The input will consist of a series of pairs and integers i and j, one pair of integers per line.
All integers will be less than 1,000,000 and greater than 0.

Output:
  For each pair of integers i and j, output i, j in the same order in which they appeared in the
input and then the maximum cycle-length for integers between and including i and j. These numbers
should be separated by one space, with all three numbers on one line and with one line of output
for each line of input.

Sample Input:         Sample Output:
1 10                  1 10 20
100 200               100 200 125
201 210               201 210 89
900 1000              900 1000 174
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cin;

int generateSequenceSize(int in) {
  int length = 0;
  while (in != 1) {
    length++;
    if (in%2 == 0) {
      in /= 2;
    } else if (in%2 != 0) {
      in *= 3;
      in++;
    }
    if (in == 1) length++;
}
  return length;
}

int main() {
  int hMTimes;
  cin >> hMTimes;
  for(int i = 0 ; i < hMTimes ; i++) {
    int s, e;
    cin >> s >> e;
    int max = 0;
    for (int j = s ; j != e+1 ; j++) {
      int curr = generateSequenceSize(j);
      if (curr > max) max = curr;
    }
    cout << s << " " << e << " " << max << endl;;
  }

  return 0;
}
