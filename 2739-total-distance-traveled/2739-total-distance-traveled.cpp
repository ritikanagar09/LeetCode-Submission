class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        
        
        int dist=0;
        
        while(mainTank-5>=0 && additionalTank){
            
                mainTank-=5;
                dist+=50;
                
                    // dist+=10;
                    additionalTank--;
            mainTank++;
               
           
            
            
        }
        
        
        
                dist+=mainTank*10;
                // mainTank=0;
            
        
        return dist;
    }
};