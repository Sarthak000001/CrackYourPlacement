class NumArray {
    vector<int>segment;
    int size;
    //building segment tree
    void buildSeg(int i,int left,int right,vector<int>&nums){
        if(left == right){
            segment[i] = nums[left];
            return;
        }
        
        int mid = (left + right)/2;
        buildSeg(2*i+1,left,mid,nums); //left child
        buildSeg(2*i+2,mid+1,right,nums);
        
        //sum query
        segment[i] = segment[2*i+1] + segment[2*i+2];
    }
    //sum query
    int querySum(int left,int right,int i,int start,int end){
        //out of bound
        if(right < start || end  < left || left > right){
            return 0;
        }
        //entirely in the range
        if(left >= start && right <= end){
            return segment[i];
        }
        
        //overlapped
        int mid = (left+right)/2;
        return querySum(left,mid,2*i+1,start,end) + querySum(mid+1,right,2*i+2,start,end);
    }
    //update query /single point update
    void queryUpdate(int left,int right,int i,int index,int val){
        if(left == right){
            segment[i] = val;
            return;
        }
        
        int mid = (left+right)/2;
        if(index <= mid){
            //left child
            queryUpdate(left,mid,2*i+1,index,val);
        }
        else{
            //right child
            queryUpdate(mid+1,right,2*i+2,index,val);
        }
        
        //after updating leaf re-evaluate the value of segment tree
        segment[i] = segment[2*i+1] + segment[2*i+2];
    }
public:
    NumArray(vector<int>& nums) {
        this->size = nums.size();
        segment.resize(4*size);
        buildSeg(0,0,size-1,nums);
    }
    
    void update(int index, int val) {
        queryUpdate(0,size-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
        return querySum(0,size-1,0,left,right);
    }
    // void updateRange(){
    //     //Lazy Propagation 
    // }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */