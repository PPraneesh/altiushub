#include<bits/stdc++.h>
using namespace std;
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [1,-1,-1,3,5,6]

int main(){
    // input phase
    int n; // size of nums;
    cin>>n;
    int k; // window size;
    cin>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    // answer - brute force - O(klogk* (n-k)) would be time complexity and space would be O(k) ;
    vector<int> ans;
    for(int i=0;i<n-k+1;i++){
        int median;
        // storing in a temporary array to sort and find median
        vector<int> temp(nums.begin()+i, nums.begin()+i+k);
        // sorting to find median
        sort(temp.begin(),temp.end());
        int mIndex1 = k/2;
        
        // based on size of window we will find the median!
        if(k%2 == 0){
            median = (temp[mIndex1] + temp[mIndex1+1])/2;
        }else{
            median = temp[mIndex1];
        }
        ans.push_back(median);
    }

    cout<<"answer "<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

}