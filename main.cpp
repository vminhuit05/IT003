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

/*void heap_sort(int left, int right)
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
*/
void heapify(vector<int>& arr, int n, int i) {
    // Find the largest among the root and its children
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// A function to perform heapsort on an array
void heap_sort(vector<int>& arr) {
    int n = arr.size();

    // Build a max heap from the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract the elements from the heap one by one and place them in the sorted array
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (largest element) with the last element of the heap
        swap(arr[0], arr[i]);
        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
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

//    for heap sort
    vector<int> arr;
    for (int i =0;i<inf;i++)
    {
        int hi;
        cin>>hi;
        arr.push_back(hi);
    }

    auto start = std::chrono::system_clock::now();

//    mergeSort(1, inf);
    normal_sort(1, inf);
//    heap_sort(arr);   
//    quickSort(1, inf);

    auto ends = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = ends - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(ends);

    cout<<elapsed_seconds.count()*1000<<'\n';

    // for(int i = 1; i <= inf; i++) cout << arr[i] << ' ';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.inp1.txt","r",stdin);
    freopen("result1.out.txt","w",stdout);
    process();
    /*freopen("number.inp2.txt","r",stdin);
    process();
    freopen("number.inp3.txt","r",stdin);
    process();
    freopen("number.inp4.txt","r",stdin);
    process();
    freopen("number.inp5.txt","r",stdin);
    process();
    freopen("number.inp6.txt","r",stdin);
    process();
    freopen("number.inp7.txt","r",stdin);
    process();
    freopen("number.inp8.txt","r",stdin);
    process();
    freopen("number.inp9.txt","r",stdin);
    process();
    freopen("number.inp10.txt","r",stdin);
    process();*/

    return 0;
}
