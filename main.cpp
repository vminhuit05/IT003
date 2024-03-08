#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
using namespace std;
const int inf = 1000000;

int a[inf + 50];
int L[inf + 50], M[inf + 50];

void heap_sort(int left, int right)
{
    priority_queue<int, vector<int>, greater<int>> check;

    for(int i = left; i <= right; i++)
    {
        check.push(a[i]);
    }

    for(int i = left; i <= right; i++)
    {
        a[i] = check.top();
         check.pop();
    }

    return;
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}


int partify (int low, int high)
{
    int pivot = a[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && a[left] < pivot) left++;
        while(right >= left && a[right] > pivot) right--;
        if (left >= right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partify(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
void mergex(int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  for (int i = 0; i < n1; i++)
    L[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = a[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    mergex(l, m, r);
  }
}

void normal_sort(int l, int r)
{
    sort(a + l, a + l + r);
}

void process()
{
    for(int i = 1; i <= inf; i++)
    {
        cin >> a[i];
    }


    auto start = std::chrono::system_clock::now();

    mergeSort(1, inf);
    //normal_sort(1, inf);
    //heap_sort(1, inf);
    //quickSort(1, inf);

    auto ends = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = ends - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(ends);

    cout<<elapsed_seconds.count()*1000<<'\n';

    //for(int i = 1; i <= inf; i++) cout << a[i] << ' ';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number1.out.txt","r",stdin);
    process();
    freopen("number2.out.txt","r",stdin);
    process();
    freopen("number3.out.txt","r",stdin);
    process();
    freopen("number4.out.txt","r",stdin);
    process();
    freopen("number5.out.txt","r",stdin);
    process();
    freopen("number6.out.txt","r",stdin);
    process();
    freopen("number7.out.txt","r",stdin);
    process();
    freopen("number8.out.txt","r",stdin);
    process();
    freopen("number9.out.txt","r",stdin);
    process();
    freopen("number10.out.txt","r",stdin);
    process();

    return 0;
}
