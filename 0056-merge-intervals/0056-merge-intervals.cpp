class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
	int l1=arr[0][0];
	int r1=arr[0][1];


	vector<vector<int>>res;
	for(int i=1;i<n;i++){
		int l2=arr[i][0];
		int r2=arr[i][1];
		
		// cout<<l1<<" "<<r1<<endl;
		if(l1<=l2 && l2 <= r1){
			r1=max(r1,r2);
		}else{
			// cout<<"////"<<endl;
			vector<int>temp={l1,r1};
			res.push_back(temp);
			l1=l2;
			r1=r2;
		}
	}
        
        vector<int>temp={l1,r1};
			res.push_back(temp);

	return res;
    }
};