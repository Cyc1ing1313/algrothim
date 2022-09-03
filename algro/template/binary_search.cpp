#include <bits/stdc++.h>
using namespace std;

int b_searc_l(int q[], int l, int r, int target) {
  while (l < r) {
    int mid = l + r >> 1;
    if (q[mid] >= target) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int b_search_r(int q[], int l, int r, int target) {
  while (l < r) {
    int mid = l + r >> 1;
    if (q[mid] <= target)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  int q[] = {1, 2, 3, 4, 5,9, 10, 11, 12};
  int n = sizeof(q) / sizeof(q[0]);
  int t = b_search_r(q, 0, n - 1, 9);
  cout << q[t] << endl;
  t = b_searc_l(q, 0, n - 1, 9);
  cout << q[t] << endl;
}