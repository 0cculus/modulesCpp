#ifndef MERGEINSERT_HPP_
# define MERGEINSERT_HPP_

# include <vector>
# include <deque>
# include <string>

template <typename T>
void insert(T& arr, int start, int range)
{
	for (int i = start; i < range; i++)
	{
		int j = i + 1;
		int temp = arr[j];

		while (j > start && arr[j - 1] > temp)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}

template <typename T>
void merge(T& arr, int start, int range, int end)
{
	int size1 = range - start + 1;
	int size2 = end - range;
	T leftArr(arr.begin() + start, arr.begin() + range + 1);
	T rightArr(arr.begin() + range + 1, arr.begin() + end + 1);
	int leftIndex = 0, rightIndex = 0;

	for (int i = start; i <= end; i++)
	{
		if (rightIndex == size2)
			arr[i] = leftArr[leftIndex++];
		else if (leftIndex == size1)
			arr[i] = rightArr[rightIndex++];
		else if (rightArr[rightIndex] > leftArr[leftIndex])
			arr[i] = leftArr[leftIndex++];
		else
			arr[i] = rightArr[rightIndex++];
	}
}

template <typename T>
void sort(T& arr, int start, int end, const int K)
{
	if (end - start > K)
	{
		int range = (start + end) / 2;
		sort(arr, start, range, K);
		sort(arr, range + 1, end, K);
		merge(arr, start, range, end);
	}
	else
		insert(arr, start, end);
}

class PmergeMe
{
	private:
		std::vector<int> vc;
		std::deque<int> dq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);
		~PmergeMe();

		std::vector<int>& getVc();
		std::deque<int>& getDq();

		void sorting(std::string type);
};

#endif
