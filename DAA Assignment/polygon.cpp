#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
   double x, y;
};

// Checking if a point is inside a polygon
bool point_in_polygon(Point point, vector<Point> polygon) {
  
   int num_vertices = polygon.size();
  
   double x = point.x, y = point.y;
  
   bool inside = false;
  
   // Store the first point in the polygon and initialize the second point
   Point p1 = polygon[0], p2;
  
   // Loop through each edge in the polygon
   for (int i = 1; i <= num_vertices; i++) {
      
       // Get the next point in the polygon
       p2 = polygon[i % num_vertices];
      
       // Check if the point is above the minimum y coordinate of the edge
       if (y > min(p1.y, p2.y)) {
          
           // Check if the point is below the maximum y coordinate of the edge
           if (y <= max(p1.y, p2.y)) {
              
               // Check if the point is to the left of the maximum x coordinate of the edge
               if (x <= max(p1.x, p2.x)) {
                  
                   /*
                        Calculate the x-intersection of the line connecting the point to the edge
                   */
                   double x_intersection = (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
                  
                   // Check if the point is on the same line as the edge or to the left of the x-intersection
                   if (abs(p1.y - p2.y) < 1e-10 && abs(y - p1.y) < 1e-10 && x >= min(p1.x, p2.x) && x <= max(p1.x, p2.x)) {
                       // point is on the edge of the polygon
                       return true;
                   } else if (abs(p1.y - p2.y) > 1e-10 && x <= x_intersection) {
                       // Flip the inside flag
                       inside = !inside;
                   }
               }
           }
       }
      
       // Store the current point as the first point for the next iteration
       p1 = p2;
   }
  
   // Return the value of the inside flag
   return inside;
}


int main() {
  
   // Define a point to test
   Point point = {0.0,1.5};
  
   // Define a polygon
   vector<Point> polygon = {{0, 1}, {0,2}, {1, 1.5}};
  
   if (point_in_polygon(point, polygon)) {
       cout << "Point is inside the polygon" << endl;
   } else {
       cout << "Point is outside the polygon" << endl;
   }
   return 0;
}