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
    int search();
    void remove();

};

A::A(int size)
{
    if (size <= 0)
    {
        cout << "空间太小";
        exit(-1);
    }
    max = size;
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

int A::search()
{
    int temp = data[0], num = 0;
    for (int i = 0; i < max; i++)
    {
        if (data[i] <= temp)
        {
            temp = data[i];
            num = i;
        }
    }
    return num;
}

void A::remove()
{
    int dire = search();
    for (int i = dire; i < max; i++)
    {
        data[i] = data[i + 1];
    }
}

int main()
{

    int size, target;

    while (cin >> size)
    {
        if (size == -1)break;
        //cin >> size;
        A seqlist(size);
        seqlist.input(size);
    
      
        seqlist.remove();
        seqlist.output(size - 1 );



    }

}

