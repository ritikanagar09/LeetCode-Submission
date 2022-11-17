class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        
        int a= abs(ax1-ax2) * abs(ay1-ay2);
        int b= abs(bx1-bx2) * abs(by1-by2);
        
        if(bx1 > ax2 || bx2 < ax1 || (by1 > ay2 || by2 < ay1)){
            // intersecting 
            //1 new rec 
            // nx1 nx2 , ny1 ny2
            
            return a+b;
            
            
            
        }else {
            int nx1=max(ax1,bx1);
            int nx2=min(ax2,bx2);
            
            int ny1=max(ay1,by1);
            
            int ny2=min(ay2,by2);
            
            int c= abs(nx1-nx2) * abs(ny1-ny2);
            return a+b-c;
        }
        
        
    }
};

    