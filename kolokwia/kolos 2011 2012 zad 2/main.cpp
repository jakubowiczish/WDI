#include <iostream>
#include <limits.h>
#include <math.h>
/*
 Mamy dany zbiór punktów.
type
punkt=record
x:integer;
y:integer;
end;
tab=array[1..max] of punkt;
Napisz funkcjê, która zwróci najmniejsz¹ odleg³oœæ miêdzy œrodkami ciê¿koœci 2 niepustych podzbiorów
tego zbioru.
*/
using namespace std;

const int N = 3;

double min_3(double a, double b, double c)
{
    if (a <= b)
    {
        if (a <= c){
            return a;
        }
        else{
            return c;
        }
    }
    else{
        if (c <= b){
            return c;
        }
        else{
            return b;
        }
    }
}

double distance(double x_1, double y_1, double x_2, double y_2)
{
    return sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
}

double min_distance(int left_subset_sum_x, int left_subset_sum_y, int left_subset_size,
                    int right_subset_sum_x, int right_subset_sum_y, int right_subset_size,
                    int x[N], int y[N], int step)
{
    if (step == N)
    {
        if (left_subset_size != 0 && right_subset_size != 0)
        {
            double left_center_x = left_subset_sum_x /  left_subset_size;
            double left_center_y = left_subset_sum_y /  left_subset_size;
            double right_center_x = right_subset_sum_x / right_subset_size;
            double right_center_y = right_subset_sum_y / right_subset_size;

            return distance(left_center_x, left_center_y, right_center_x, right_center_y);
        }
        else
        {
            return INT_MAX;
        }
    }
    else

        return min_3(
                   min_distance(left_subset_sum_x + x[step], left_subset_sum_y + y[step], left_subset_size + 1, right_subset_sum_x, right_subset_sum_y, right_subset_size, x, y,step + 1),
                   min_distance(left_subset_sum_x, left_subset_sum_y, left_subset_size, right_subset_sum_x  + x[step], right_subset_sum_y + y[step], right_subset_size + 1, x, y,step + 1),
                   min_distance(left_subset_sum_x, left_subset_sum_y, left_subset_size, right_subset_sum_x, right_subset_sum_y, right_subset_size, x, y,step + 1)
               );
}

int main()
{
    int x[N] = {1,2,5};
    int y[N] = {1,2,5};
    cout << min_distance(0,0,0,0,0,0,x,y,0) << endl;
    return 0;
}
