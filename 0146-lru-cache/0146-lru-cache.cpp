class LRUCache {
public:
    map<int,int>mp;
    map<int, list<int> :: iterator> addr;
    list<int>l1;
    int cap;
    int siz;
    LRUCache(int capacity) {
        cap=capacity;
        siz=0;
        
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        
        // ushe key ko vnha ush particulr psoition se htao or front me rkh do
        
        list<int>::iterator it=addr[key];
        l1.erase(addr[key]);
        addr.erase(key);
        
        
        l1.push_front(key);
        addr[key]=l1.begin();
        
        return mp[key];
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            // agar vo key already exist karti h toh
            // l1.erase(key);//------ bcoz tu direct key remove kar vaa rhi h
            // you need to mention the address of key that need to be deleted 
            l1.erase(addr[key]);
            mp.erase(key);//bcoz new key value pair daalenge
            addr.erase(key);
            siz--;
            
            
        }
        
        
        // 2nd conditon ki cache bahr gyi 
        
        if(siz==cap){
            int key=l1.back();// matlab hume bss key se matlab h or kuc nhi 
            l1.erase(addr[key]);
            addr.erase(key);
            mp.erase(key);
            siz--;
        }
        
        
        
        // push vala kaam baad me kar rhe hai
        
        l1.push_front(key);
        addr[key]=l1.begin();
        mp[key]=value;
        
        siz++;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */