// popr 2 wdi 16


#include <iostream>
#include <vector>

using namespace std;

class Point{
    int x,y;
public:
    Point (int x2, int y2)
    {
        x = x2;
        y = y2;
    }
void show()
{
    cout<<x<<" "<<y<<endl;
}
int getx()
{
    return x;
}
int gety()
{
    return y;
}
};

int main()
{
    vector <Point> punkt;
    vector <Point> cw1;
    vector <Point> cw2;
    vector <Point> cw3;
    vector <Point> cw4;

    punkt.push_back(Point(1,2));
    punkt.push_back(Point(1,3));
    punkt.push_back(Point(-1,3));
    punkt.push_back(Point(-2,-3));
    punkt.push_back(Point(1,-3));

    for(int i=0; i<punkt.size(); i++)
    {
        Point p = punkt.at(i);
        if(p.getx() > 0 && p.gety() > 0)
        {
            cw1.push_back(p);
        }
        if(p.getx() > 0 && p.gety() < 0)
        {
            cw4.push_back(p);
        }
        if(p.getx() < 0 && p.gety() > 0)
        {
            cw2.push_back(p);
        }
        if(p.getx() < 0 && p.gety() < 0)
        {
            cw3.push_back(p);
        }
    }
    cout<<"w cwiartce 1: ";
    for(int i=0; i<cw1.size(); i++)
    {
        cw1.at(i).show();
    }
    cout<<endl;
    cout<<"w cwiartce 2: ";
    for(int i=0; i<cw2.size(); i++)
    {
        cw2.at(i).show();
    }
    cout<<endl;
    cout<<"w cwiartce 3: ";
    for(int i=0; i<cw3.size(); i++)
    {
        cw3.at(i).show();
    }
    cout<<endl;
    cout<<"w cwiartce 4: ";
    for(int i=0; i<cw4.size(); i++)
    {
        cw4.at(i).show();
    }
    cout<<endl;

    return 0;
}
