/*编程，定义“点”类 Point，包含数据成员x、y（坐标点），成员函数包括：
（1）构造函数，有2个带默认值0的参数。
（2）设置x坐标值。
（3）设置y坐标值。
（4）获取x坐标值。
（5）获取y坐标值。
（6）两点间距离计算函数。*/
#include<iostream>
#include<cmath>
using namespace std;

class Point
{
private:
    int m_x;
    int m_y;
public:
    Point():m_x(0),m_y(0){}
    Point(int x,int y){
        m_x=x;
        m_y=y;
    }
    void setinformation(int x,int y){
        m_x=x;
        m_y=y;
    }
    int distance(const Point& p)const;
};
int Point::distance(const Point& p) const
{
    int dx=m_x-p.m_x;
    int dy=m_y-p.m_y;
    return sqrt(dx*dx+dy*dy);
}

class circle:public Point
{
private:
    int m_radius;
public:
    circle():Point(0,0),m_radius(0){}
    circle(int x,int y,int radius){
        Point(x,y);
        m_radius=radius;
    }
    void panduan(const Point& p){
        int d=distance(p);
        if(m_radius<d)d=1;
        else if(m_radius==d)d=0;
        else d=-1;
        switch(d){
            case 1:
            cout<<"圆外";
            break;
            case 2:
            cout<<"圆上";
            break;
            case -1:
            cout<<"圆内";
            break;
        }
    }
};

int main()
{
    int x1,x2,y1,y2,r;
    cin>>x1>>x2>>y1>>y2>>r;
    Point s1(x1,y1);
    circle s2(x2,y2,r);
    s2.panduan(s1);
    return 0;
}