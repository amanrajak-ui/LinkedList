// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int>sortedArray(vector<int>&arr)
// {
//     int temp =arr[0];
//     for(int i=1;i<arr.size();i++)
//     {
//         arr[i-1]=arr[i];
//     }

//     arr[arr.size()-1]=temp;

//     return arr;

// }
// int main()
// {
//     vector<int>arr={1,2,3,4,5};

//     vector<int> newArray = sortedArray(arr);

//     for(auto value : newArray)
//     {
//         cout<<value<<" ";
//     }

// }

// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> removeDuplicate(vector<int>&arr)
// {
//     vector<int>ans;
//     for(int i=0;i<arr.size();i++)
//     {
//         if(arr[i]!=arr[i+1])
//         {
//             ans.push_back(arr[i]);
//         }
//         // else
//         // {
//         //     ans.pop_back();
//         // }
//     }
//     return ans;
// }
// int main()
// {
//     vector<int>arr{0,0,3,3,5,6};

//     vector<int>newArray = removeDuplicate(arr);

//     cout<<"without duplicate element array"<<endl;
//     for(auto value :newArray)
//     {
//         cout<<value<<" ";
//     }

//     cout<<endl;

    
// }


#include<iostream>
#include<vector>
using namespace std;
int removeDuplicate(vector<int>&arr)
{
    vector<int>ans;
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=arr[i+1])
        {
            ans.push_back(arr[i]);
            count++;
        }
        // else
        // {
        //     ans.pop_back();
        // }
    }
    return count;
}
int main()
{
    vector<int>arr{0,0,3,3,5,6};

    int newArray = removeDuplicate(arr);

    cout<<"length : "<<newArray;


   

    
}