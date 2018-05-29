//1. o(n^2)简单

//选择排序
template<Typename T>
void selectionSort( arr[], int n){
    for(int i = 0; i < n ;  i++){
        int minIndex = i;
        for(int j = i + 1; j<n; j++){
            if(arr[j] < arr[i])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);//交换比较耗时
    }
}
//插入排序-对于近乎有序的数组速度非常快-o(n^2)
template<typename T>
void insertSort( T arr[], int n){
    for(int i = 1; i < n ; i++){
        for(int j = i ; j > 0; j --){
            if(arr[j] < arr[j-1])
                swap(arr[i], arr[j-1]);
            else
                break;
        }
    }
}
//版本2
template<typename T>
void insertSort(T arr[], int n){
    for(int i =1; i < n; i++){
        for(int j = i; j > 0 && arr[j]<arr[j-1]; j--){
            swap(arr[j], arr[j-1]);
        }
    }
}
//插入优化,进行赋值，减少交换
template<typename T>
void insertSort(T arr[], int n){
    for(int i = 1; i < n ; i++){
        T e = arr[i];
        for(int j = i; j > 0 && e < arr[j-1]; j--){//此处为e
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}
//冒泡排序
void BubbleSort1(int array[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n-1; j++)
        {
            if (array[i]>array[j])
                swap(array, j, i);//每次i后面的元素比array[i]小就交换。
        }
    }
}
template<typename T>
void bubbleSort( T arr[] , int n){

    bool swapped;
    do{
        swapped = false;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                swap( arr[i-1] , arr[i] );
                swapped = true;
            }
        n --;
    }while(swapped);
}
//希尔排序-shell sort
template<typename T>
void shellSort(T arr[], int n){
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int h = 1;
    while( h < n/3 )
        h = 3 * h + 1;
    while( h >= 1 ){
        // h-sort the array
        for( int i = h ; i < n ; i ++ ){
            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;
            for( j = i ; j >= h && e < arr[j-h] ; j -= h )
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        h /= 3;
    }
}
//归并排序 o(nlogn)
//维护i、j、k
//merge函数对arr[l..mid]与arr[mid+1..r]进行归并排序
void merge(T arr[], int l, int mid, int r){
    if(l >= r)
        return;
    T aux[r-l+1];
    for(int i = l; i <= r; i++){
        aux[i-l] = arr[i];
    }
    int i = l, j = mid+1;
    for(int k  = l; k <= r; k++){
        if(i>mid){
            arr[k] = aux[j-l];
            j++;
        }
        else if(j > r){
            arr[k] = aux[i-l];
            i++;
        }
        else if(aux[i] < aux[j]){
            arr[k] = aux[i-l];
            i ++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}
//递归使用归并排序，对arr[l...r]进行排序
template<typename T>
void doMergeSort(T arr[], int l, int r){
    //元素量比较小时可以采取插入排序，元素量小近乎有序概率大
    if( l>= r)
        return;
    int mid = l/2 + r/2;
    doMergeSort(arr, l , mid);
    doMergeSort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1])//只有当前大于后时才进行排序--第一种优化
        merge(arr, l, mid, r)
}
template<typename T>
void mergeSort(T arr[], int n){

    doMergeSort(arr, 0, n - 1);
}
//堆排序
void heapSort1(T arr[], int n ){
}
//快速排序
void partition(int arr[], int l, int r){
    int v = arr[l];
    int j = l;
    for(int i = l+1; i <= r; i++){
        if(arr[i]<v){
            swap(arr[j+1], arr[i]);
            j++;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}
void doQuickSort(int arr[], int l, int r){
    if(l >= r )
        return;
    int p = partition(arr, l, r);
    doQuickSort(arr, l, p-1);
    doQuickSort(arr, p+1, r);
}
void quickSort(int arr[], int n){
    doQuickSort(arr, 0, n-1);
}
//优化一

//二分查找法
//对于有序数列才是用而发查找法
int binarySearch(int arr[], int n, int target){
    int l=0, r = n-1;
//    int mid = l/2 + r/2;
    while(l<=r){
        int mid = l/2 + r/2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            r= mid-1;
        else
            l = mid + 1;
    }
    return -1;
}



/*
    void reOrderArray(vector<int> &array) {
        vector<int> value;
        vector<int>::iterator ib1;
        ib1=array.begin();
        while(ib1!=array.end()){
            if(*ib1%2==0){
                value.push_back(*ib1);
                ib1=array.erase(ib1);
            }
            else{ib1++;}
        }
        vector<int>::iterator ib2,ie2;
        ib2=value.begin();
        ie2=value.end();
        for(;ib2!=ie2;ib2++){
            array.push_back(*ib2);
        }
    }
    */
    /*
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        if(size == 0 || size == 1) return;
        int p = -1;
        int q = 0;
        while(q < size) {
            if ((array[q] & 1) != 0) {
                p++;
                int i = q;
                int temp = array[i];
                while(i > p) {
                    array[i] = array[i-1];
                    i--;
                }
                array[p] = temp;
            }
            q++;
        }
    }
    */
