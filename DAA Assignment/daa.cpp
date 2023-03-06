#include<bits/stdc++.h>
using namespace std;



struct Point {
   double x, y;
};
int side(Point A, Point B, Point P)
{
    const int RIGHT = 1, LEFT = -1, ZERO = 0;
	// subtracting co-ordinates of point A from
	// B and P, to make A as origin
	B.x -= A.x;
	B.y -= A.y;
	P.x -= A.x;
	P.y -= A.y;

	// Determining cross Product
	double cross_product = B.x * P.y - B.y * P.x;

	// return RIGHT if cross product is positive
	if (cross_product > 0)
		return LEFT;

	// return LEFT if cross product is negative
	if (cross_product < 0)
		return RIGHT;

	// return ZERO if cross product is zero.
	return 0;
}

bool  isInside(Point p ,vector<Point> polygon){
    int n = polygon.size();
    for (int i = 0; i < n-1; i++)
    {
        if(side(polygon[i],polygon[i+1],p) == -1){
            return false;
        }
    }
    if(side(polygon[n-1],polygon[0],p) == -1){
        return false;
    }
    return true;
}
// bool isAcute(double x1, double y1, double x2, double y2, double x3, double y3) {
//   x1 = x1 - x2;
//   y1 = y1 - y2;
//   x3 = x3 - x2;
//   y3 = y3 - y2;
//   double dot = x1 * x3 + y1 * y3;
//   double  det = x1 * y3 - y1 * x3;
//   double result = atan2(det, dot);
//   double res =  ((result < 0) ? (result * 180 / 3.141592) + 360
//                        : (result * 180 / 3.141592));
//     // double final = 360 - res;
//     if(res > 180)
//         return 0;
//     else 
//         return 1;
 
// }

bool isAcute(Point p1,Point p2 , Point p3){
    double x1,y1,x2,y2,x3,y3;
    x1 = p1.x;
    y1 = p1.y;
    x2 = p2.x;
    y2 = p2.y;
    x3 = p3.x;
    y3 = p3.y;
      x1 = x1 - x2;
  y1 = y1 - y2;
  x3 = x3 - x2;
  y3 = y3 - y2;
  double dot = x1 * x3 + y1 * y3;
  double  det = x1 * y3 - y1 * x3;
  double result = atan2(det, dot);
  double res =  ((result < 0) ? (result * 180 / 3.141592) + 360
                       : (result * 180 / 3.141592));
    // double final = 360 - res;
    if(res > 180)
        return 0;
    else 
        return 1;

}

vector<Point> notches(vector<Point> p){
    vector<Point> d;
    int s = p.size();
    if(! isAcute(p[s-1],p[0],p[1])){
        d.push_back(p[0]);
    }
    for(int i = 1; i<s;i++){
        if(! isAcute(p[i-1],p[i],p[(i+1)%s])){
            d.push_back(p[i]);
    }
    }
    return d;
}

void fun(vector<Point> poly,vector<vector<Point>> & ans){
    vector<Point> N = notches(poly);
    int s = poly.size();
    if(N.size()==0){
        ans.push_back(poly);
        return;
    }
    vector<Point> L; // v1, v2,.................., 
    int start = 0;
    while (true)
    {
        L.push_back(poly[start]);
        L.push_back(poly[(start+1)%s]);
        int i = (start+2)%s;
        while (isAcute())
        {
            /* code */
        }
        


    }
    
   
    
}

int main()
{
    vector<Point> pol1,pol2,pol3;
    pol2 = {{0,0},{3,-2},{-3,0}};
    pol1 = {{0,0},{-2,4},{2,4},{0,2},{2,0}};
    pol3 = {{2,0},{5,4},{8,0},{5,2}};
    vector<Point> nots;
    nots = notches(pol3);
    // cout<<nots.size()<<endl;

    for(int i = 0; i< nots.size();i++){
        cout<<nots[i].x<<","<<nots[i].y <<endl;
    }

 return 0;
}