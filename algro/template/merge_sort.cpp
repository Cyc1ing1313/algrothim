#include <bits/stdc++.h>

using namespace std;
const int LEN = 1000;
int temp[LEN];

void merge_sort(int q[], int l, int r) {
  if (l >= r)
    return;
  int mid = l + r >> 1;
  merge_sort(q, l, mid);
  merge_sort(q, mid + 1, r);
  int k = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i] < q[j])
      temp[k++] = q[i++];
    else
      temp[k++] = q[j++];
  }
  while (i <= mid)
    temp[k++] = q[i++];
  while (j <= r)
    temp[k++] = q[j++];
    for(i=l,j=0;i<=r;i++,j++) {
        q[i] = temp[j];
    }
}

int main() {
    int q[] = {
        1,2,3,-1,0,0
    };
    int n = sizeof(q)/sizeof(q[0]);
    merge_sort(q,0,n-1);
    for(int i=0;i<n;i++) {
        cout << q[i] << endl;
    }
}