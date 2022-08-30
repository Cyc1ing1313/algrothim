#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void quick_sort(int a[], int l, int r) {
  if (l >= r)
    return;
  int i = l - 1, j = r + 1, x = a[l];
  while (i < j) {
    while (a[++i] < x)
      ;
    while (a[--j] > x)
      ;
    if (i < j)
      swap(a[i], a[j]);
    else
      break;
  }
  quick_sort(a, l, j);
  quick_sort(a, j + 1, r);
}

int main() {
  int a[] = {0, 2, 1, 4, 4,-1};
  int n = sizeof(a)/sizeof(a[0]);
  quick_sort(a, 0, n-1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}