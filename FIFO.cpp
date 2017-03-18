#include "FIFO.h"

//auto first = [](Process left, Process right) {
//	return (left.get_introduced() > right.get_introduced());
//};


struct CompIntroduced{
	bool operator()(Process const & left, Process const & right){
		return left.get_introduced() > right.get_introduced();
	}
};

int FIFO(Process * plist, int len){
	std::priority_queue<Process, std::vector<Process>,CompIntroduced> pq;
	int i = 0;
	while (i < len){
		pq.push(plist[i]);
		i++;
	}
	int t = 0;
	i = 0;
	while (pq.empty() != 1){
		Process running = pq.top();
		if (running.get_introduced() > t){
			t++;//wait
		}
		else{
			pq.pop();
			while (running.get_remaining() != 0){
				t++;
				running.dec_remaining();
			}
			int total = (t-running.get_introduced());
			running.set_tt(total);
			plist[i] = running;
			i++;
		}
	}
	return 1;
}
