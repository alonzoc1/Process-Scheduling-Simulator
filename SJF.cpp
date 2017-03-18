#include "SJF.h"

struct CompRemain{
	bool operator()(Process const & left, Process const & right){
		return left.get_remaining() > right.get_remaining();
	}
};

int index_process(Process * plist, int len, int id){
	int i = 0;
	while (i < len){
		if (plist[i].get_id() == id)
			return i;
		else
			i++;
	}
	return -1;
}

int SJF(Process * plist, int len){
	std::priority_queue<Process, std::vector<Process>, CompRemain> pq;
	int i = 0;
	while (i < len){
		pq.push(plist[i]);
		i++;
	}
	int t = 0;
	std::vector<Process> store;
	while (pq.empty() != 1){
		Process contend = pq.top();
		//std::cout << "Top is: " << contend.get_id();//debug
		//std::cout << "With required: " << contend.get_required();//debug
		//std::cout << std::endl;//debug
		while ((contend.get_introduced() > t) && (pq.empty() == 0)){
			store.push_back(pq.top());
			pq.pop();
			contend = pq.top();
			//std::cout << "Top is: " << contend.get_id();//debug
			//std::cout << "With required: " << contend.get_required();//debug
			//std::cout << std::endl;//debug
		}
		if (contend.get_introduced() > t){
			t++;//wait
			while (store.empty() == 0){
				pq.push(store.back());
				store.pop_back();
			}
		}
		else{
			pq.pop();
			while (store.empty() == 0){
				pq.push(store.back());
				store.pop_back();
			}
			while (contend.get_remaining() != 0){
				t++;
				contend.dec_remaining();
			}
			int total = (t-contend.get_introduced());
			contend.set_tt(total);
			plist[index_process(plist, len, contend.get_id())] = contend;
		}
	}
	return 1;
}
