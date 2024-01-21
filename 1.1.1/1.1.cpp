//时间复杂度：O（n）

#include <iostream>
#include<fstream>

using namespace std;

class A
{
    int* data;
    int max;

public:
    A(int size);
    void input(int size);
    void output(int size);
    int search(int i);
    void insert(int i);
};

A::A(int size)
{
    if (size <= 0)
    {
        cout << "空间太小";
        exit(-1);
    }
    max = size + 1;
    data = new int[max];
    if (data == 0)
    {
        cout << "error";
        exit(-1);
    }
}


void A::input(int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }
}

void A::output(int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] <<' ';
    }
    cout << endl;
}

int A::search(int j)
{
    int Max, Min;
    Max = Min = data[0];
    for (int i = 0; i < max-1; i++)
    {
        if (data[i] >= Max)Max = data[i];
        if (data[i] <= Min)Min = data[i];
    }
    for (int i = 0; i < max-1; i++)
    {
        if (j >= Max)return max;
        if (j <= Min)return 0;
        if (data[i + 1] >= j && data[i] <= j)return i + 1;
    }
    return 0;
}

void A::insert(int j)
{
    int dire = search(j);
    for (int i = max; i >= dire; i--)
    {
        data[i] = data[i - 1];
    }
    data[dire] = j;
}

int main()
{

    int size, target;

    while (cin >> size)
    {
        if (size == -1)break;
        
        A seqlist(size);

        seqlist.input(size);
        seqlist.output(size);
        cin >> target;
        
        
        seqlist.insert(target);
        
        seqlist.output(size + 1);

    }


}

