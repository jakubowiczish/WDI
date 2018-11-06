#include <iostream>
/*
Proszê napisaæ procedurê która dostaje w parametrach dwie tablice i
przepisuje z pierwszej do drugiej najd³u¿szy ci¹g malej¹cy
*/
using namespace std;
const int N = 6;

void przepisz(int tab[N])
{
    int length = 1;
    int max_length = -1;

    int sequence_start = 0;
    int max_sequence_start = 0;

    for(int i=0; i < N-1; i++)
    {
        if(tab[i+1] < tab[i])
        {
            length++;
        }

        else
        {
            if(length > max_length)
            {
                max_length = length;
                max_sequence_start = sequence_start;
            }

            sequence_start = i + 1;
            length = 1;
        }
    }

    if(length > max_length)
    {
        max_length = length;
        max_sequence_start = sequence_start;
    }

    cout<<"Maksymalna dlugosc ciagu malejacego to: "<<max_length<<endl;
    cout<<"Ostateczny index poczatkowego elementu tego ciagu to: "<<max_sequence_start<<endl;

    cout<<"Najdluzszy ciag malejacy: "<<endl;

    int przepisana[max_length];
    for(int j=max_sequence_start, i=0; j < max_sequence_start + max_length, i < max_length; j++,i++)
    {
        przepisana[i] = tab[j];
        cout<<przepisana[i]<<" ";
    }
}

int main()
{
    int tablicawlasciwa[N];

    tablicawlasciwa[0] = 6;
    tablicawlasciwa[1] = 5;
    tablicawlasciwa[2] = 4;
    tablicawlasciwa[3] = 3;
    tablicawlasciwa[4] = 2;
    tablicawlasciwa[5] = 1;

    przepisz(tablicawlasciwa);

    return 0;
}
