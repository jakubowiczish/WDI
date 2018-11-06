#include <iostream>
/*
Ile jest liczb ”235” (czyli nie maj¹cych w rozk³adzie czynników innych ni¿ 2,3,5)?
(w przedziale 1...N (jedynka jest tak¹ liczb¹)).
*/

using namespace std;

int main()
{
    int N;
    cin >> N;
    int p2, p3, p5;
    int counter = 0;
    p2 = 1;

    while(p2 <= N)
    {
        p3 = p2;
        while(p3 <= N)
        {
            p5 = p3;
            while(p5 <= N)
            {
                p5 *= 5;
                counter++;
            }
        p3 *= 3;
        }
    p2 *= 2;
    }

    cout<<counter;
    return 0;
}
