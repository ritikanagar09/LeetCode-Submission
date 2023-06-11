class SnapshotArray {
public:
    // index-> {snapid,value}
    map<int,map<int,int>>snaps;
    int snapid=0;
    SnapshotArray(int length) {
        for(int i=0;i<length;i++){
            map<int,int>mpp;
            mpp[0]=0;
            snaps[i]=mpp;
        }
    }
    
    void set(int index, int val) {
        snaps[index][snapid]=val;
    }
    
    int snap() {
        
        return snapid++;
        
    }
    
    int get(int index, int snap_id) {
        auto it =snaps[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */