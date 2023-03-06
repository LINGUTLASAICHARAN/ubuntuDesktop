#include<bits/stdc++.h>

using namespace std; 





#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define INSIDE 1
#define OUTSIDE 0

typedef struct {
   double x,y;
} Point;

bool InsidePolygon(Point polygon [],int N,Point p)
{
  int counter = 0;
  int i;
  double xinters;
  Point p1,p2;

  p1 = polygon[0];
  for (i=1;i<=N;i++) {
    p2 = polygon[i % N];
    if (p.y > MIN(p1.y,p2.y)) {
      if (p.y <= MAX(p1.y,p2.y)) {
        if (p.x <= MAX(p1.x,p2.x)) {
          if (p1.y != p2.y) {
            xinters = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
            if (p1.x == p2.x || p.x <= xinters)
              counter++;
          }
        }
      }
    }
    p1 = p2;
  }

  if (counter % 2 == 0)
    return(true);
  else
    return(false);
}

int main(){

   // Define a point to test
   Point point = {0.0,-1.5};
  
   // Define a polygon
   Point polygon[] = {{0, 1}, {0,2}, {1, 1.5}};
  
   if (InsidePolygon(polygon,3,point)) {
       cout << "Point is inside the polygon" << endl;
   } else {
       cout << "Point is outside the polygon" << endl;
   }


}