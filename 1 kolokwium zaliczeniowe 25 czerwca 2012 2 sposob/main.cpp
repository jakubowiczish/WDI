#include <iostream>
#include <cstdlib>
#include <ctime>
/*Mamy tablicê [1..max,1..max]. Napisz funkcjê, która zwraca d³ugoœæ najd³u¿szego podci¹gu rosn¹cego
znajduj¹cego siê w dowolnym (jednym) wierszu, którego wszystkie elementy s¹ ze sob¹ wzglêdnie
pierwsze. */

using namespace std;
const int N = 5;
int LCD (int a, int b) //largest common divisor
{
    int c;
    while(b != 0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
void printtable(int t[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool are_all_elements_in_row_coprime(int t[N][N], int row)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if(LCD(t[row][i], t[row][j]) != 1)
            {
                return false;
            }
        }
    }
    return true;
}

int count_length_of_longest_increasing_subsequence_in_row(int t[N][N], int row)
{
    int max_length = 1;
    int actual_length = 1;

    for (int i = 0; i < N - 1; i++)
    {
        if (t[row][i + 1] > t[row][i])
        {
            actual_length++;
            if (actual_length > max_length)
            {
                max_length = actual_length;
            }
        }
        else
        {
            actual_length = 1;
        }
    }
    return max_length;
}

int longest_increasing_subsequence(int t[N][N]) // sprawdza czy wszystkie liczby w danym wierszu sa wzglednie pierwsze wobec siebie, jesli tak
{
    int result = -1;
    for (int row = 0;  row < N; row++)
    {
        if (are_all_elements_in_row_coprime(t, row))
        {
            int length_of_longest_increasing_subsequence_in_row = count_length_of_longest_increasing_subsequence_in_row(t, row);
            if (length_of_longest_increasing_subsequence_in_row > result)
            {
                    result = length_of_longest_increasing_subsequence_in_row;
            }

        }
    }

    return result;
}

int main()
{
    srand(time(NULL));
    int t[N][N];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            t[i][j] = rand() % 50 + 1;
        }
    }
    printtable(t);
    cout<<longest_increasing_subsequence(t)<<endl;
    return 0;
}
