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
    // answer - better
    vector<int> ans;

    // let's sort the first window and find the answer, should have time complexity around O(klogk + n-k+1), space would be O(k)
    vector<int> temp(nums.begin(), nums.begin()+k);
    sort(temp.begin(),temp.end());

    int median;
    int mIndex1 = k/2;
    if(k%2 == 0){
        median = (temp[mIndex1] + temp[mIndex1+1])/2;
    }else{
        median = temp[mIndex1];
    }
    ans.push_back(median);

    // now we will use sliding window approach to eliminate sorting
    // we could remove the first element from the temp array and place the next element in its correct position
    for(int i=1;i<n-k+1;i++){
        int elementToInsert = nums[i+k-1];
        temp.erase(nums.begin()+i-1);

        // inserting it in the correct place
        for(int j=0;j<k;j++){
            if(elementToInsert > temp[j]){
                temp.insert(temp.begin()+j,elementToInsert);
            }
        }
        int mIndex1 = k/2;
        
        // based on size of window we will find the median!
        if(k%2 == 0){
            median = (temp[mIndex1] + temp[mIndex1+1])/2;
        }else{
            median = temp[mIndex1];
        }
        ans.push_back(median);
    }

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    
}