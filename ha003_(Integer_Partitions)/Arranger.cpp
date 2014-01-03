// by ballypc
// Dec. 2013

#include <iostream>

#include "Arranger.h"


void Arranger::_s_output (const int arr[], int len)
{
	std::cout<<arr[0];
	for (int i=1; i<len; ++i) std::cout<<","<<arr[i];
	std::cout<<std::endl;

	return;
}


void Arranger::_arrange (int arr[], int sum, int boxes) const
{
	if (boxes==1) {
		arr[0]=sum;
		this->_output_arr();
		return;
	}
	for (arr[0]=sum; arr[0]>=0; --arr[0]) {
		this->_arrange(arr+1, sum-arr[0], boxes-1);
	}
}

void Arranger::_arrange_noempty (int arr[], int sum, int boxes) const
{
	if (boxes==1) {
		arr[0]=sum;
		this->_output_arr();
		return;
	}
	for (arr[0]=sum-boxes+1; arr[0]>=1; --arr[0]) {
		this->_arrange_noempty(arr+1, sum-arr[0], boxes-1);
	}
}


void Arranger::_arrange_order (int arr[], int sum, int boxes, int max) const
{
	if (boxes==1) {
		arr[0]=sum;
		this->_output_arr();
		return;
	}
//	int boxes1=boxes-1;
	if (max > sum) max=sum;
	for (arr[0]=max; boxes*arr[0]>=sum; --arr[0]) {
		this->_arrange_order(arr+1, sum-arr[0], boxes-1, arr[0]);
	}
}


void Arranger::_arrange_order_noempty (int arr[], int sum, int boxes, int max) const
{
	if (boxes==1) {
		arr[0]=sum;
		this->_output_arr();
		return;
	}
	int boxes1=boxes-1;
	if (max > sum-boxes1) max=sum-boxes1;
	for (arr[0]=max; boxes*arr[0]>=sum; --arr[0]) {
		this->_arrange_order_noempty(arr+1, sum-arr[0], boxes1, arr[0]);
	}
}