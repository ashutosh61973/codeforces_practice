#include "bits/stdc++.h"
using namespace std;
template <typename T>
class myvector
{
    T *v;
    int sz;
    int current;

public:
    myvector()
    {
        v = new T[1];
        sz = 1;
        current = 0;
    }
    void push(T value)
    {
        if (current == sz)
        {
            T *temp = new T[2 * sz];

            for (int i = 0; i < sz; i++)
            {
                temp[i] = v[i];
            }
            delete[] v;
            sz *= 2;
            v = temp;
        }
        v[current] = value;
        current++;
    }
    void assing(int value, int index)
    {
        if (index == capacity)
            push(data);
        else
            arr[index] = value;
    }

    void pop() { current--; }
    int size() { return current; }
    void print()
    {
        for (int i = 0; i < current; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
////////////////////////////////////////////////////////////////////////
template <typename T>
class all_sort
{
private:
    vector<T> v;

public:
    all_sort(int n)
    {
        v.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
    }
    void print();
    void slection_sort();
    void insertion_sort();
};
template <typename T>
void all_sort<T>::print()
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
template <typename T>
void all_sort<T>::slection_sort()
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (v[j] < v[min_idx])
                min_idx = j;

        swap(&v[min_idx], &v[i]);
    }
    cout << "slection_sort";
    print();
}
template <typename T>
void all_sort<T>::insertion_sort()
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
    cout << "insertion_sort";
    print();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // memset(prime, true, sizeof(prime));
    //primes(); // primes under 1lakh

    /*
  #ifdef NCR
        init();
    #endif
*/
    int n;
    cin >> n;
    all_sort<int> O(n);
    O.insertion_sort();
    O.selection_sort();
}
