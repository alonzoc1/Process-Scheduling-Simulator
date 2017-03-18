#include "SRT.h"

struct CompRemain1{
	bool operator()(Process const & left, Process const & right){
		if (left.get_remaining() == right.get_remaining()){
			return left.get_id() > right.get_id();
		}
		return left.get_remaining() > right.get_remaining();
	}
};

struct CompIntroduced1{
	bool operator()(Process const & left, Process const & right){
		if (left.get_introduced() == right.get_introduced()){
			return left.get_id() > right.get_id();
		}
		return left.get_introduced() > right.get_introduced();
	}
};

int index_process2(Process * plist, int len, int id){
	int i = 0;
	while (i < len){
		if (plist[i].get_id() == id)
			return i;
		else
			i++;
	}
	return -1;
}

int SRT(Process * plist, int len){
	std::priority_queue<Process, std::vector<Process>, CompIntroduced1> arrival;
	std::priority_queue<Process, std::vector<Process>, CompRemain1> remain;
	int t = 0;//time
	int i = 0;
	while (i < len){
		arrival.push(plist[i]);
		i++;
	}
	Process active(-1, 1000000, -1);
	while ( (arrival.empty() == 0) || (remain.empty() == 0) ){
		if (arrival.empty() == 0){
			Process transfer = arrival.top();
			while (transfer.get_introduced() <= t){
				remain.push(transfer);
				arrival.pop();
				if (arrival.empty() == 0){
					transfer = arrival.top();
				}
				else{
					Process new2(100000, 100000, -1);
					transfer = new2;
				}
			}
		}
		
		if (remain.empty() == 0){
			if (active.get_remaining() > remain.top().get_remaining()){
				if (active.get_id() != -1){
					remain.push(active);
					active = remain.top();
					remain.pop();
				}
				else{
					active = remain.top();
					remain.pop();
				}
			}
		}
		
		active.dec_remaining();
		t++;
		if (active.get_remaining() == 0){
			active.set_tt( (t-active.get_introduced()));
			plist[index_process2(plist, len, active.get_id())] = active;
			if (remain.empty() == 0){
				active = remain.top();
				remain.pop();
			}
			else{
				Process newactive(-1, 1000000, -1);
				active = newactive;
			}
		}
	}
	if ( (active.get_id() != -1) && (active.get_remaining() > 0) ){
		while (active.get_remaining() > 0){
			active.dec_remaining();
			t++;
		}
		int total = (t-active.get_introduced());
		active.set_tt(total);
		plist[index_process2(plist, len, active.get_id())] = active;
	}
	return 1;
}
