#include<iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int>& num, vector<int>& combination, int i, int k,vector<vector<int>>& result){

    if(k==0){
        result.push_back(combination);
        return;
    }
    
    if (i == num.size()){
        return;
    }
    

    combination.push_back(num[i]);
    findCombinations(num, combination, i+1, k-1, result);

    combination.pop_back();
    findCombinations(num,combination,i+1,k, result);

}

int main(){

    int n,k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    vector<int> nums;
    vector<int> combination;
    vector<vector<int>> result;

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++){
        int input;
       cin >> input; 
       nums.push_back(input);
    }


    findCombinations(nums,combination,0,k,result);

    cout << "Your combinations are: " << endl;
    for (vector<int> comb : result){
        for (int num : comb){
            cout << num << " ";
        }
        cout << endl;
    }


    return 0;
}