    #include <iostream>
    #include <math.h>
    #include <vector>
    #include <fstream>
     
    using namespace std;
     
    class Edge;
    class Face;
    class Vertex
    {
    public:
        int x, y;
        vector<Edge *> outgoingEdges; // outgoing edges
        Vertex(int a, int b)
        {
            x = a;
            y = b;
        }
    };
     
    class Edge
    {
     
    public:
        Vertex *origin; // e.destination = e.twin.origin
        Edge *twin;
        Face *left;
        vector<Edge *> nextEdges, previousEdges; // in counter clockwise wrt to face
    };
     
    class Face
    {
     
    public:
        Edge *incidet; // anti-clock wise
    };
     
    class DCEL
    {
    public:
        vector<Vertex *> v; // vertices
     
        vector<Edge *> e; // edges
     
        vector<Face *> f; // faces
     
        // add edge
        void addVertex(int x, int y);
        // add  edge
        void addEdge(int x1, int y1, int x2, int y2);
        // add face
    };
     
    void DCEL ::addVertex(int x, int y)
    {
        Vertex *vnew = new Vertex(x, y);
        v.push_back(vnew);
    }
    void DCEL::addEdge(int x1, int y1, int x2, int y2)
    {
        Edge *e1 = new Edge();
        Edge *e2 = new Edge();
     
        e.push_back(e1);
        e.push_back(e2);
     
        Vertex *v1, *v2;
     
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i]->x == x1 && v[i]->y == y1)
            {
                v1 = v[i];
            }
            if (v[i]->x == x2 && v[i]->y == y2)
            {
                v2 = v[i];
            }
        }
     
        e1->twin = e2;
        e2->twin = e1;
     
        e1->origin = v1;
        e2->origin = v2;
     
        e1->nextEdges = v2->outgoingEdges;
        e2->nextEdges = v1->outgoingEdges;
     
        e1->previousEdges = v1->outgoingEdges;
     
        // cout << (int )(e1->previousEdges.size())-1 <<"  "<< i<<endl;
        for (int i = 0; i < (int)(e1->previousEdges.size()) - 1; i++)
        {
            e1->previousEdges[i] = e1->previousEdges[i]->twin;
        }
     
        e2->previousEdges = v2->outgoingEdges;
        for (int i = 0; i < (int)(e2->previousEdges.size()) - 1; i++)
        {
            e2->previousEdges[i] = e2->previousEdges[i]->twin;
        }
     
        // adding outgoing edges at the end so that next edges and previous edges won't get affected
        v1->outgoingEdges.push_back(e1);
        v2->outgoingEdges.push_back(e2);
    }
     
    class Point{
        public:
            double x, y;
    };
     
     
    int side(Point* A, Point* B, Point* P)
    {
        const int RIGHT = 1, LEFT = -1, ZERO = 0;
    	// subtracting co-ordinates of point A from
    	// B and P, to make A as origin
        int ax = A->x, bx = B->x, px = P->x, ay = A->y, by = B->y, py = P->y;  
    	bx -= ax;
    	by -= ay;
    	px -= ax;
    	py -= ay;
     
    	// Determining cross Product
    	double cross_product = bx * py - by * px;
     
    	// return RIGHT if cross product is positive
    	if (cross_product > 0)
    		return LEFT;
     
    	// return LEFT if cross product is negative
    	if (cross_product < 0)
    		return RIGHT;
     
    	// return ZERO if cross product is zero.
    	return ZERO;
    }
     
     
     
    bool  isInside(Point* p ,vector<Point*> polygon){
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
     
    bool isAcute(Point* p1, Point* p2, Point* p3) {
     
        double x1 = p1->x;
        double y1 = p1->y;
     
        double x2 = p2->x;
        double y2 = p2->y;
     
        double x3 = p3->x;
        double y3 = p3->y;
     
      x1 = x1 - x2;
      y1 = y1 - y2;
      x3 = x3 - x2;
      y3 = y3 - y2;
      double dot = x1 * x3 + y1 * y3;
      double  det = x1 * y3 - y1 * x3;
      double result = atan2(det, dot);
      double res =  ((result < 0) ? (result * 180 / 3.141592) + 360
                           : (result * 180 / 3.141592));
        if(result == 0){
            cout<<"180";
            return 1;
        }
        if(res > 180)
            return 0;
        else 
            return 1;
     
    }
     
    vector<Point*> notches(vector<Point*> inp){
        vector<Point*> notches;
        for(int i = 2; i < inp.size(); i++){
            if(!isAcute(inp[i-2], inp[i-1], inp[i]))
                notches.push_back(inp[i-1]);       
        }
     
        if(!isAcute(inp[inp.size()-2],  inp[inp.size()-1], inp[0]))
            notches.push_back(inp[inp.size()-1]);
        if(!isAcute(inp[inp.size()-1], inp[0], inp[1]))
            notches.push_back(inp[0]);
        return notches;
    }
     
    vector<Point*> checkNotch(vector<Point*> inp, vector<Point*> poly){
        vector<Point*> notch = notches(poly);
        vector<Point*> res;
        for(int i = 0; i < inp.size(); i++){
            for(int j = 0; j < notch.size(); j++){
                if(inp[i] == notch[j]){
                    res.push_back(inp[i]);
                    break;
                }   
            }
        }
        return res;
    }
     
    Point* Next(Point* v, vector<Point*> poly){
        int ind = -1;
        for(int i = 0; i < poly.size(); i++){
            if(poly[i] == v){
                ind = i;
                break;
            }
        }
        if(ind == poly.size()-1)
            return poly[0];
        return poly[ind+1];
    }
     
    void remove_side(Point* p, vector<Point*> L, Point* p1, vector<Point*>& Lf){
        int s = side(p, p1, L[L.size()-1]);
        for(int i = 0; i < L.size(); i++){
            if(side(p, p1, L[i]) == s)
                Lf.erase(Lf.begin() + i);
        }
    }
     
    void fun(vector<Point*> poly,vector<vector<Point*>>& ans){
            vector<Point*> nots = notches(poly);
            if(nots.size() == 0){
                ans.push_back(poly);
                return;
            }
     
            vector<vector<Point*>> L(50);
            int m = 1;
            L[0].push_back(poly[0]);
            //L.push_back(poly[1]);
            while(poly.size() > 3){
                //can change initialisation
                vector<Point*> temp(50);
                //temp[0] = new Point(); 
                temp[1] = L[m-1][L[m-1].size()-1];
                temp[2] = Next(temp[1], poly);
                L[m].push_back(temp[1]);
                L[m].push_back(temp[2]);
                int i = 2; 
                temp[i+1] = Next(temp[i], poly);
                
                while( isAcute(temp[i-1], temp[i], temp[i+1]) && isAcute(temp[i], temp[i+1], temp[1]) && isAcute(temp[i+1], temp[1], temp[2]) && L[m].size() < poly.size()){
                    L[m].push_back(temp[i+1]);
                    i++;
                    temp[i+1] = Next(temp[i], poly);
                    //seg fault possible, no pushes to temp[i];
                }
                bool t = isAcute(temp[i+1], temp[1], temp[2]);
     
                //3.4
     
                if(L[m].size() != poly.size()){
     
                    //3.4.1  
                    vector<Point*> cover; // P - L[m]
                    for(auto i: poly)
                        cover.push_back(i);
                    for(int i = 0; i < L[m].size(); i++){
                        int s = cover.size();
                        for(int j = 0; j < s; j++){
                            if(cover[j] == L[m][i])
                                cover.erase(cover.begin() + j);
                        }
                    }
                    vector<Point*> notch = checkNotch(cover, poly);
     
                    //3.4.2
                    if(notch.size() > 0){
                        int s = notch.size();
                        for(int i = 0; i < s; i++){
                            bool t = isInside(notch[i], L[m]);
                            if(t){
                                remove_side(notch[i], L[m], temp[1], L[m]);
                            }      
                        }
                    }
     
                }
                
                //3.5
     
                if(L[m][L[m].size()-1] != temp[2]){
                    ans.push_back(L[m]);
     
                    for(int i = 1; i < L[m].size()-1; i++){
                    int s = poly.size();
                        for(int j = 0; j < s; j++){
                            if(L[m][i] == poly[j])
                                poly.erase(poly.begin() + j);
                        }
                    }
                    
                }    
                m += 1;
            }
            
        
    }
     
    int main(){
     
        fstream file("inp.txt");
        
        int n;
        file>>n;
        //DCEL* poly = new DCEL();
        vector<Point*> inp;
        for(int i = 0; i < n; i++){
            double x, y;
            file>>x>>y;
            //cout<<x<<" "<<y<<endl;
            Point* p = new Point();
            p->x = x;
            p->y = y;
            inp.push_back(p);
        }
        file.close();
        vector<vector<Point*>> ans;
        fun(inp, ans);
        ofstream myfile;
    myfile.open("Points.txt");
    for(int i = 0; i < ans.size(); i++){
        cout<<"vector"<<endl;
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]->x<<" "<<ans[i][j]->y<<endl;
        }
    }
 
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            myfile<<ans[i][j]->x<<" "<<ans[i][j]->y<<" "<<ans[i][(j+1)%ans[i].size()]->x<<" "<<ans[i][(j+1)%ans[i].size()]->y<<endl;
        }
    }
        return 0;
    }