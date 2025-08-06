class SegmentTree{

public:
    vector<int> seg;
    int n;

    SegmentTree(vector<int>& arr){
        n = arr.size();
        seg.resize(4*n);
        build(0,0,n-1,arr);
    }

    void build(int ind , int low , int high , vector<int>&arr ){
        if(low==high){
            seg[ind]=arr[low];
            return ;
        }

        int mid = (low+high)/2;

        build(2*ind+1 , low , mid , arr);
        build(2*ind+2 , mid+1 , high , arr);

        seg[ind] = max( seg[2*ind+1]  , seg[2*ind+2]);
    }

    int query(int ind , int low , int high , int l , int r){

        if(high<l || low>r) return INT_MIN;

        if(low>=l && high<=r) return seg[ind];

        int mid = (low+high)/2;

        int left = query(2*ind+1 , low , mid , l , r);
        int right = query(2*ind+2 ,mid+1 , high , l , r);

        return max(left,right);
    }

    void update(int ind , int low  , int high , int i , int val , vector<int>&arr){

        if(low == high){
            seg[ind]=val;
            arr[low]=val;
            return ;
        }

        int mid = (low+high)/2;

        if(i<=mid) update(2*ind+1 , low , mid , i , val , arr);
        else update(2*ind+2 , mid+1 , high , i , val , arr);

        seg[ind] = max( seg[2*ind +1] , seg[2*ind + 2]);
    }

    int findIndex(int ind , int low , int high , int target){

        if(seg[ind] < target) return -1;
        if(low == high) return low;

        int mid = (low+high)/2;
        int left = seg[2*ind+1];

        if(left>=target) {
            return findIndex(2*ind+1 , low , mid , target);
        }
        else return findIndex(2*ind+2 , mid+1 , high , target);
    }

};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();
        SegmentTree tree(baskets);

        int unplaced = 0 ;

        for(int i = 0 ; i<fruits.size() ; i++){

            int fruitSize = fruits[i];
            int idx = tree.findIndex(0,0,n-1,fruitSize);
            if(idx==-1){
                unplaced++;
            }
            else tree.update(0,0,n-1,idx,-1,baskets);
        }

        return unplaced;
    }
};