#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

constexpr int TenThousand = 10000;
constexpr int OneHundred = 100;

void PrintFirstFifty(int* array){
    cout<<"printed massive: ";
    for (int i = 0; i < 50; ++i)
        cout << array[i] << " ";
    cout<<endl;
}

void FillMassiveForRandom(int* array, int size, int minVal, int maxVal){
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> distribution(minVal + 1, maxVal - 1);
    for (int i = 0; i < size; ++i) 
        array[i] = distribution(generator);
}

int Search(const int* array, int size, int searchingVal){
    for (int i = 0; i < size; ++i)
        if(array[i] == searchingVal)
            return i;
    return -1;
}

void Swap(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void QuickSort(int *array, int start, int end)
{
    int i = start;
    int j = end;
    int pivot = array[(i + j) / 2];

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            Swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    if (j > start)
        QuickSort(array, start, j);
    if (i < end)
        QuickSort(array, i, end);
}

int LomutoPartition(int *array, int start, int end) {
    int pivot = array[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            Swap(&array[i], &array[j]);
        }
    }
    Swap(&array[i + 1], &array[end]);
    return (i + 1);
}

void QuickSortIterative(int *array, int start, int end) {
    int stack[end - start + 1];
    int top = -1;

    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0) {
        end = stack[top--];
        start = stack[top--];

        int p = LomutoPartition(array, start, end);

        if (p - 1 > start) {
            stack[++top] = start;
            stack[++top] = p - 1;
        }

        if (p + 1 < end) {
            stack[++top] = p + 1;
            stack[++top] = end;
        }
    }
}

int RecursiveBSearch(int* array, int value, int left, int right) {
    int mid = (right + left) / 2;
    if(array[mid] == value)
        return mid;
    if(array[mid] > value)
        return RecursiveBSearch(array, value, left, mid);
    if(array[mid] < value)
        return RecursiveBSearch(array, value, mid + 1, right);
    return -1;
}

int BSearch(const int* array, int value, int left, int right) {
    while (right >= left){
        int mid = (right + left) / 2;
        if(array[mid] == value)
            return mid;
        if(array[mid] > value)
            right = mid;
        if(array[mid] < value)
            left = mid + 1;
    }
    return -1;
}

int main() {
    //Обычный линейный поиск
    int a[TenThousand];
    FillMassiveForRandom(a, TenThousand, -1000, 1000);
    cout<<"first search: "<<Search(a, TenThousand, 100) << endl;
    //Рекурсивный квик сорт
    int b[OneHundred];
    FillMassiveForRandom(b, OneHundred, -10, 10);
    PrintFirstFifty(b);
    QuickSort(b, 0, OneHundred - 1);
    PrintFirstFifty(b);
    //Не рекурсивный квик сорт
    int c[OneHundred];
    FillMassiveForRandom(c, OneHundred, -10, 10);
    PrintFirstFifty(c);
    QuickSortIterative(c, 0, OneHundred);
    PrintFirstFifty(c);
    //Бинарные поиски
    int f[] = {1, 2, 3, 4, 5};
    cout << RecursiveBSearch(f, 1, 0, 4) << endl;
    cout << BSearch(f, 5, 0, 4) << endl;
    // Сранение времени
    int g[OneHundred];
    FillMassiveForRandom(g, OneHundred, -10, 10);
    PrintFirstFifty(g);
    
    auto startTimeForUnsortedLinear = std::chrono::steady_clock::now();
    Search(g, OneHundred, 5);
    auto endTimeForUnsortedLinear = std::chrono::steady_clock::now();
    
    auto startTimeForSortedRBS = std::chrono::steady_clock::now();
    RecursiveBSearch(g, 5, 0, OneHundred);
    auto endTimeForSortedRBS = std::chrono::steady_clock::now();
    
    auto startTimeForSortedBS = std::chrono::steady_clock::now();
    BSearch(g, 5, 0, OneHundred);
    auto endTimeForSortedBS = std::chrono::steady_clock::now();
    
    auto elapsedForUnsortedLinear = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeForUnsortedLinear - startTimeForUnsortedLinear);
    auto elapsedForSortedRBS = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeForSortedRBS - startTimeForSortedRBS);
    auto elapsedForSortedBS = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeForSortedBS - startTimeForSortedBS);
    
    std::cout << "The linear unsorted search time: " << elapsedForUnsortedLinear.count() << " ns"<<endl;
    std::cout << "The binary recursive sorted  time: " << elapsedForSortedRBS.count() << " ns"<<endl;
    std::cout << "The binary iterable sorted time: " << elapsedForSortedBS.count() << " ns"<<endl;
    return 0;
}
