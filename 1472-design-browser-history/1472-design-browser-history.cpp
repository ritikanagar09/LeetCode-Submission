class BrowserHistory {
public:
    string hp;
    stack<string>os;
    stack<string>fs;
    BrowserHistory(string homepage) {
        hp=homepage;
        
        os.push(homepage);
    }
    
    void visit(string url) {
        os.push(url);
        
        // removing forward history 
        while(!fs.empty()){
            fs.pop();
        }
    }
    
    string back(int steps) {
        
        // if(steps>os.size()){
        //     return hp;
        // }
        int s=0;
        while(s<steps && os.size()>1){
            string otop=os.top();
            
            os.pop();
            
            fs.push(otop);
            s++;
        }
        
       
        
        
        return os.top();
        
        
    }
    
    string forward(int steps) {
        
//         if(fs.size()==0){
//             if(!os.empty()){
//                 return os.top();
//             }
//             else {
//                 return hp;
//             }
            
//         }
        
        int s=0;
        while(s<steps && !fs.empty()){
            string top=fs.top();
            fs.pop();
            os.push(top);
            s++;
        }
        
        return os.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */