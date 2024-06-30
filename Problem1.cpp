// Approach 1:
// Time Complexity : O(n)
// Space Complexity : O(1)
//
// Approach 2:
// Time Complexity : O(log n)
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : 


/*
geek for geeks link : https://www.geeksforgeeks.org/find-the-missing-number-in-a-sorted-array/

Find the Missing Number in a sorted array
Given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list. One of the integers is missing in the list. Write an efficient code to find the missing integer. 
Examples: 
Input : arr[] = [1, 2, 3, 4, 6, 7, 8]
Output : 5

Input : arr[] = [1, 2, 3, 4, 5, 6, 8, 9]
Output : 7
*/




/**
 * 
 * Approach 1 : Checking each element in a for loop
*/

#include <iostream>
using namespace std;

int findMissing(int arr[], int size) {
    for(int i = 0; i<size; i++){
        if(arr[i] != i+1) return i+1;
    }
    return 0;
}

int main(){
    //int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int arr[] = {2, 3, 4, 5, 6, 7, 8};
    //int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = findMissing(arr, size);
    std::cout << "Missing number number is = " << result << std::endl;

    return 0;
}



/* Approach 2 : 
If only one number is missing, then when we divide the array in two half; missing number 
will be only in one half. Therefore, we can reduce the search set by half in each iteration.

If arr[mid] == mid+1; that means there is no missing number on left side of the array.

Also, we are checking on both sides of the mid for missing number.
*/

#include <iostream>
using namespace std;


int findMissing(int arr[], int size) {
    int low = 0;
    int high = size -1;
    if(arr[0] != 1) return 1;

    while(low <= high){
        int mid = high - (high - low)/2;
        if(mid !=0 && ((arr[mid-1] ==mid) && (arr[mid]-mid != 1))){
            return mid+1;
        } else if(arr[mid] != mid+1) {
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }

    return -1;

}



int main(){
    //int arr[] = {1, 2, 3, 4, 6, 7, 8};
    //int arr[] = {2, 3, 4, 5, 6, 7, 8};
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = findMissing(arr, size);
    std::cout << "Missing number number is = " << result << std::endl;

    return 0;
}



/* Approach 3 : 
*/


#include <iostream>
using namespace std;


int findMissing(int arr[], int size) {
    int low = 0;
    int high = size -1;

    if(arr[0] != 1) return 1;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(mid != 0 && arr[mid]-1 != arr[mid-1]){
            return arr[mid]-1;
        } else if (mid <high && arr[mid]+1 != arr[mid+1]){
            return arr[mid]+1;
        }
        if(arr[mid] == mid+1){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;

}


int main(){
    //int arr[] = {1, 2, 3, 4, 6, 7, 8};
    //int arr[] = {2, 3, 4, 5, 6, 7, 8};
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = findMissing(arr, size);
    std::cout << "Missing number number is = " << result << std::endl;

    return 0;
}