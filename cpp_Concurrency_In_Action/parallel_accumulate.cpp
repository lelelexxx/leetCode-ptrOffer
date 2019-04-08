#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
#include<numeric>
#include<chrono>
template<typename iterator, typename T>
struct accumulate_block
{
	void operator()(iterator first, iterator last, T& result)
	{
		result = std::accumulate(first, last, result);
	}
};

template<typename iterator, typename T>
T parallel_accumulate(iterator first, iterator last, T init)
{
	unsigned long const length = std::distance(first, last);//Ԫ�ظ���
	if (!length)  //���ֻ��һ��Ԫ��
		return init;
	unsigned long const min_per_thread = 25;
	unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;

	unsigned long const hardware_threads = std::thread::hardware_concurrency();

	unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

	unsigned long const block_size = length / num_threads;

	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);//��һ������Ϊ��ǰҲ��һ���߳�

	iterator block_start = first;

	for (unsigned long i = 0; i < (num_threads - 1); ++i)
	{
		iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(accumulate_block<iterator, T>(),
			block_start, block_end, std::ref(results[i]));//Ϊ���̼߳�ͨ�ţ�����ǿ�ƴ�������
		block_start = block_end;
	}

	accumulate_block<iterator, T>()(block_start, last, results[num_threads - 1]);//ʣ�µ��ڵ�ǰ�߳��и㶨,���ﴴ��һ����ʱ����ֱ�ӵ��������ص�()��
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	return std::accumulate(results.begin(), results.end(), init);

}

int main()
{
	std::vector<unsigned long> x;
	unsigned long count=0;
	std::cout << "�������ۼӷ�Χn��0~n��,�������" << std::endl;
	std::cin >> count;
	for (unsigned long i = 0; i < count ;i++)
		x.push_back(i);
	
	auto start = std::chrono::system_clock::now();
	unsigned long res = 0;
	res = parallel_accumulate(x.begin(), x.end(), res);//���̰߳汾accumulate
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << res << "time of multiThread: "<< duration.count()/1000 <<std::endl;
	
	unsigned long res_main = 0;
	for (unsigned long i = 0; i < count; i++)
		res_main += x[i];
	auto end2 = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end2 - end);
	std::cout << res_main << "time of for: " << duration.count() / 1000 << std::endl;

	
}