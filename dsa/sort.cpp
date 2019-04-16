#include<vector>
#include<iostream>

using namespace std;
class bubbleSort
{
public:
	void operator()(vector<int>& v, int start, int end)
	{
		while (!bubble(v, start, end--));
	}
private:
	bool bubble( vector<int>&  v, int start, int end)
	{
		bool flag = true;
		while (++start <= end)
		{
			if (v[start - 1] > v[start])
			{
				flag = false;
				int temp = v[start];
				v[start] = v[start - 1];
				v[start - 1] = temp;
			}
		}
		return flag;
	}
};
class mergeSort
{
private:
	void merge(vector<int> &v, int start, int mid, int end)
	{
		vector<int> leftSub(v.begin() + start, v.begin() + mid + 1);
		vector<int> rightSub(v.begin() + mid+1, v.begin()+ end +1);

		int leftIndex = 0, rightIndex = 0;
		leftSub.push_back(numeric_limits<int>::max()); //在尾部插入极大值，可以省去判断左右为空。
		rightSub.push_back(numeric_limits<int>::max());
		while (start <= end)
		{
			if (leftSub[leftIndex] < rightSub[rightIndex])
			{
				v[start++] = leftSub[leftIndex++];
			}
			else
			{
				v[start++] = rightSub[rightIndex++];
			}
		}
	}
	void merge_Sort(vector<int>& v, int start, int end)
	{	
		if (start>=end)
			return ;
		int mid = start + ((end - start) >> 1);

	    merge_Sort(v, start, mid);
		merge_Sort(v, mid+1, end);
		merge(v, start, mid, end);
	}
public:
	void operator()(vector<int>& v, int start, int end)
	{
		merge_Sort(v, start, end);

	}

};
class quickSort {
private:
	int partial(vector<int>& v, int start, int end)
	{
		int mid = v[end];
		int count = start - 1;
		for (int i = start; i < end; i++)
		{
			if (v[i] <= mid)
			{
				count += 1;
				int temp = v[i];
				v[i] = v[count];
				v[count] = temp;
			}	
		}
		v[end] = v[++count];
		v[count] = mid;
		return count;
	}
	void quick_Sort(vector<int>& v, int start, int end)
	{
		if (start >= end)
			return;
		int mid = partial(v, start, end);
		quick_Sort(v, start, mid-1);  //mid的位置已经确定，这里就需要把mid排除在外。
		quick_Sort(v, mid + 1, end);
	}
public:
	void operator()(vector<int>& v, int start, int end) 
	{
		quick_Sort(v, start, end);
	}
};

class heapSort 
{
public:
	void operator()(vector<int>& v) {
		heap_Sort(v);
	}
private:
	void shiftDown(vector<int>& v, int start, int end )
	{
		int parent = start;
		int son = parent*2 + 1;
		
		while (son <= end)
		{	
			if (son + 1 < end && v[son] < v[son + 1])
				son++;
			if (v[parent] > v[son])
				return;
			else 
			{
				swap(v[parent], v[son]);
				parent = son;
				son = parent * 2 + 1;
			}
		}
		
	}
	void heap_Sort(vector<int>& v)
	{

		for (int i = v.size() / 2-1; i >= 0; i--)
		{
			shiftDown(v, i, v.size()-1);
		}
		for (int i = v.size() - 1; i >= 0; i--)
		{
			swap(v[0], v[i]);
			shiftDown(v, 0, i - 1);
		}
	}

};
int main()
{
	vector<int> vec{ 3,1,4,2,5,7,9,5,3,1 };
	bubbleSort bs;
	bs(vec, 0, vec.size() - 1);
	for (auto x : vec) cout << x <<',';
	cout << endl;
	
	vector<int> vec2{ 3,1,4,2,5,7,9,5,3,1 };
	mergeSort ms;
	ms(vec2,0,vec2.size()-1);
	for (auto x : vec2) cout << x << ',';
	cout << endl;

	vector<int> vec3{ 3,1,4,2,5,7,9,5,3,1 };
	quickSort qs;
	qs(vec3, 0, vec.size() - 1);
	for (auto x : vec3) cout << x << ',';
	cout << endl;
	

	vector<int> vec4{ 3,1,4,2,5,7,9,5,3,1 };
	heapSort hs;
	hs(vec4);
	for (auto x : vec4) cout << x << ',';
	cout << endl;

}