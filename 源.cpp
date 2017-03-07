#include<iostream>
#include"string.h"
#include"stdlib.h"
using namespace std;

int Find_Max_Crosssing_Subarray(int a[],int first,int mid,int last){
	float sum = 0;
	int left_sum = INT_MIN, max_left = INT_MIN, max_right = INT_MIN, right_sum = INT_MIN;
	for (int i = mid; i >first; i--){
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
 	}
	
	sum = 0;
	for (int j = mid + 1; j < last; j++)
	{
		sum += a[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}
	return (left_sum+right_sum);
}
int Find_Maximum_Subarray(int a[], int first, int last){
	if (first == last)
		return(a[first]);
	else
	{
		int mid = (first + last) / 2;
		int left_sum = Find_Maximum_Subarray(a, first, mid);
		int right_sum = Find_Maximum_Subarray(a, mid + 1, last);
		int cross_sum = Find_Max_Crosssing_Subarray(a, first, mid, last);
		if (left_sum >= right_sum && left_sum >= cross_sum)
			return (left_sum);
		else if (right_sum >= left_sum && right_sum >= cross_sum)
			return(right_sum);
		else
			return (cross_sum);
	}
}
int main(){

	int n;
	cout << "请输入数组元素的个数：" << endl;
	cin >> n;
	int *arr = new int[n];
	if (arr == NULL)
		return false;
	cout << "请输入数组元素：" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "最大子数组的和为：" << Find_Maximum_Subarray(arr, 0, n - 1) << endl;
	system("pause");
	return 0;
}