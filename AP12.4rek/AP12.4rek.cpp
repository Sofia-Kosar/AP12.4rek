#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void LAdd(Elem*& L, Elem* T, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL)
    {
        if (T->link != L)
            LAdd(L, T->link, value);
        else
            T->link = tmp;
    }
    else
        L = tmp;
    tmp->link = L;
}

void LPrint(Elem* first, Elem* L)
{
    if (L == first)
    {
        cout << L->info << "  ";
        LPrint(first, L->link);
    }
    else if (L->link != first)
    {
        cout << L->info << "  ";
        LPrint(first, L->link);
    }
    else
    {
        cout << L->info << "  ";
        cout << endl;
    }
}

int LCount(Elem* first, Elem* L, Info x, int k) //1
{
    if (L == first && first->info == x)         //2
    {
        LCount(first, L->link, x, k + 1);       //3
    }
    else if (L->link != first)                  //4
    {
        if (L->info != x)
            LCount(first, L->link, x, k);       //5
        else                                    //6
            LCount(first, L->link, x, k + 1);   //7
    }
    else
    {
        if (L->info == x)                       //6
            k++;                                //7
        return k;                               //8
    }
}

void LIter(Elem*& L, int i, int imax)
{
    int value;
    if (i < imax)
    {
        cout << "Enter the value : ";
        cin >> value;
        LAdd(L, L, value);
        LIter(L, i + 1, imax);
    }
}

int main()
{
    Elem* L = NULL; Elem* tmp = new Elem; int imax, value;
    cout << "Enter the amount of values : ";
    cin >> imax;
    LIter(L, 0, imax);
    LPrint(L, L);
    cout << "Enter the value of selected elements : ";
    cin >> value;
    cout << "The amount of elements with value of " << value << " : " << LCount(L, L, value, 0) << endl;
}
