#include<iostream>
#include<cmath>
using namespace std;
int count = 0;
void merge(int arr[], int left, int mid, int right) {
    count++;
    int n1 = mid - left + 1; // SIZE
    int n2 = right - mid; // SIZE
    cout << "\t\tN = " << count << endl;
    int L[n1], M[n2];
    cout << "Size of L : " << n1 << "  Size of M : " << n2 << endl; 
    cout << "Array of N : { ";
    for(int i = 0 ; i < (n1+n2) ; i++){
      cout << arr[i] << " ";
    }
    cout << "}" << endl;
    cout << "L = { ";
    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
        cout << L[i] << " ";
    }
    cout << "}" << endl;
    cout << "M = { ";
    for (int j = 0; j < n2; j++){
        M[j] = arr[mid + 1 + j];
        cout << M[j] << " ";
    }
    cout << "}" << endl;
    int i, j, k;
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) { // swap or input into array_w
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) { 
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
    cout << "Sort L And M : " << " {"; 
    for(int w = 0 ; w < (n1+n2);w++){
        cout << arr[w] << " ";
    }
    cout << "}" << endl;
}

void mergeSort(int arr[], int l, int r) { // array , left ,right
  if (l < r) { // left < right
    int m = floor((l + r) / 2);
    cout << "Left : " << l << " Mid : " << m << " Right : " << r  << endl;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
void DividedWatt(int arr[],int w,int s){
  float Ans[s];
  cout << "\t\tDivide of Array" << endl;
  mergeSort(arr, 0, s-1); // [0 - 5] 1-6 size 6 
  cout << "Sort : ";
  for(int w = 0 ; w < s ; w++){
    cout << arr[w] << " ";
  }
  cout << endl;
  // knap sack 0/1
  int sum = 0;
  int i = 0;
  int k = 0;
  while(i < s){
    if(w > arr[i]){
      if(w >= (arr[i] + sum)){
        sum+=arr[i];
        Ans[k] = arr[i];
        k++;
      }
    }
    i++;
  }
  cout << "Choose : ";
  for(int j = 0 ; j < k ; j++){
    cout << Ans[j] << " ";
  }
  cout << endl;
  cout << "Sum of Choose : " << sum << ", Maximum Watt : " << w << endl;
  //fixed watt
  cout << "\t\t[Divided watt]" << endl;
  float temp = 0;
  for(int q = 0 ; q < k ; q++){
    temp = Ans[q];
    Ans[q] = Ans[q]/2;
    cout << "[" << q+1 << "] " << temp << " watt : " << ((temp/w) * 100) << "% -> Divide : " << Ans[q]  << " watt -> " << (((Ans[q])/w)*100) <<"%" << endl;
  }
}
int main() {
    int x[] = {400 , 300 , 100 , 200 , 330 , 600 };
    int s = sizeof(x) / sizeof(x[0]); // size
    int w = 610;
    cout << "Array : ";
    for(int i = 0 ; i < s ; i++ ){
      cout << x[i] << " ";
    }
    cout << endl;
    cout << "Maximum Watt : " << w << endl;
    DividedWatt(x,w,s);
    return 0;
}
/*
 0     1     2     3     4     5
400 , 300 , 100 , 200 , 330 , 600
 0     1     2
 0     1
 0
                    3    4     5
                         4     5
                               5
size 6 : 0 - 5
mergeSort(array , left , right)
0 + 5 = 5 / 2 = 2.5 = 2
0 + (5 - 0)/2 = 2.5
*/