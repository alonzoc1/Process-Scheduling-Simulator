#include "MLF.h"

struct CompIntroduced2{
	bool operator()(Process const & left, Process const & right){
		if (left.get_introduced() == right.get_introduced()){
			return left.get_id() > right.get_id();
		}
		return left.get_introduced() > right.get_introduced();
	}
};

int index_process3(Process * plist, int len, int id){
	int i = 0;
	while (i < len){
		if (plist[i].get_id() == id)
			return i;
		else
			i++;
	}
	return -1;
}


int MLF(Process * plist, int len){
	std::priority_queue<Process, std::vector<Process>, CompIntroduced2> arrival;
	
	//Multilevel queues//
	std::queue<Process> Q1;
	std::queue<Process> Q2;
	std::queue<Process> Q3;
	std::queue<Process> Q4;
	std::queue<Process> Q5;
	//Where Q5 has highest priority//
	
	//Pauses
	Process p1;
	Process p2;
	Process p3;
	Process p4;
	Process p5;
	
	int i = 0;
	while (i < len){
		arrival.push(plist[i]);
		i++;
	}
	
	int t = 0;//time
	int prio = -1;
	//int slice = 1;
	Process running(-1, 1000000, -1);
	while ((arrival.empty() == 0) || (Q1.empty() == 0) || (Q2.empty() == 0)
	|| (Q3.empty() == 0) || (Q4.empty() == 0) || (Q5.empty() == 0)){
		//std::cout << "looping!" << std::endl;//debug
		//if (t >= 30)//debug
			//return 0;//debug
		if (arrival.empty() == 0){
			//std::cout << "checking arrival" << std::endl;//debug
			Process p = arrival.top();
			while (p.get_introduced() <= t){
				//std::cout << "found one!" << std::endl;//debug
				Q5.push(p);
				arrival.pop();
				if (arrival.empty() == 0){
					p = arrival.top();
				}
				else{
					//std::cout << "arrival is empty" << std::endl;//debug
					Process new2(100000, 100000, -1);
					p = new2;
				}
			}
		}
		
		if ((prio != -1) && (running.get_slice() <= 0)){
			//std::cout << "timeslot ended..." << std::endl;//debug
			Process new4(-1, 1000000, -1);
			if ((prio == 1) || (prio == 2)){
				Q1.push(running);
			}
			if (prio == 3)
				Q2.push(running);
			if (prio == 4)
				Q3.push(running);
			if (prio == 5)
				Q4.push(running);
			running = new4;
			prio = -1;
		}
		
		if (((p5.get_id() != -1) || (Q5.empty() == 0)) && (5 > prio)){
			if (prio == -1){
				if (p5.get_id() == -1){
					running = Q5.front();
					Q5.pop();
					prio = 5;
					running.set_slice(1);
				}
				else{
					running = p5;
					Process new20(-1, 100000, -1);
					p5 = new20;
					prio = 5;
				}
			}
			else{
				if ((prio == 1))
					p1 = running;
				if (prio == 2)
					p2 = running;
				if (prio == 3)
					p3 = running;
				if (prio == 4)
					p4 = running;
				if (p5.get_id() == -1){
					running = Q5.front();
					Q5.pop();
				}
				else{
					running = p5;
					Process new10(-1, 100000, -1);
					p5 = new10;
				}
				prio = 5;
				running.set_slice(1);
			}
		}
		
		if (((p4.get_id() != -1) || (Q4.empty() == 0)) && (4 > prio)){
			if (prio == -1){
				if (p4.get_id() == -1){
					running = Q4.front();
					Q4.pop();
					prio = 4;
					running.set_slice(2);
				}
				else{
					running = p4;
					Process new21(-1, 100000, -1);
					p4 = new21;
					prio = 4;
				}
			}
			else{
				if ((prio == 1))
					p1 = running;
				if (prio == 2)
					p2 = running;
				if (prio == 3)
					p3 = running;
				if (p4.get_id() == -1){
					running = Q4.front();
					Q4.pop();
				}
				else{
					running = p4;
					Process new11(-1, 100000, -1);
					p4 = new11;
				}
				prio = 4;
				running.set_slice(2);
			}
		}
		if (((p3.get_id() != -1) || (Q3.empty() == 0)) && (3 > prio)){
			if (prio == -1){
				if (p3.get_id() == -1){
					running = Q3.front();
					Q3.pop();
					prio = 3;
					running.set_slice(4);
				}
				else{
					running = p3;
					Process new23(-1, 100000, -1);
					p3 = new23;
					prio = 3;
				}
			}
			else{
				if ((prio == 1))
					p1 = running;
				if (prio == 2)
					p2 = running;
				if (p3.get_id() == -1){
					running = Q3.front();
					Q3.pop();
				}
				else{
					running = p3;
					Process new13(-1, 100000, -1);
					p3 = new13;
				}
				prio = 3;
				running.set_slice(4);
			}
		}
		
		if (((p2.get_id() != -1) || (Q2.empty() == 0)) && (2 > prio)){
			if (prio == -1){
				if (p2.get_id() == -1){
					running = Q2.front();
					Q2.pop();
					prio = 2;
					running.set_slice(8);
				}
				else{
					running = p2;
					Process new22(-1, 100000, -1);
					p2 = new22;
					prio = 2;
				}
			}
			else{
				if ((prio == 1))
					p1 = running;
				if (p2.get_id() == -1){
					running = Q2.front();
					Q2.pop();
				}
				else{
					running = p2;
					Process new12(-1, 100000, -1);
					p2 = new12;
				}
				prio = 2;
				running.set_slice(8);
			}
		}
		
		if (((p1.get_id() != -1) || (Q1.empty() == 0)) && (1 > prio)){
			if (prio == -1){
				if (p1.get_id() == -1){
					running = Q1.front();
					Q1.pop();
					prio = 1;
					running.set_slice(16);
				}
				else{
					running = p1;
					Process new26(-1, 100000, -1);
					p1 = new26;
					prio = 1;
				}
				
			}
			else{
				if (p1.get_id() == -1){
					running = Q1.front();
					Q1.pop();
				}
				else{
					running = p1;
					Process new16(-1, 100000, -1);
					p1 = new16;
				}
				prio = 1;
				running.set_slice(16);
			}
		}
		running.dec_remaining();
		//std::cout << "Running process: " << running.get_id() << std::endl;//debug
		t++;
		if (running.get_remaining() == 0){
			//std::cout << "Process " << running.get_id() << " finished!" << std::endl;//debug
			running.set_tt((t-running.get_introduced()));
			plist[index_process3(plist,len,running.get_id())] = running;
			Process new3(-1,1000000,-1);
			prio = -1;
			running = new3;
		}
		running.dec_slice();
	}
	if ((running.get_id() != -1) && (running.get_remaining() > 0)){
		while (running.get_remaining() > 0){
			running.dec_remaining();
			t++;
		}
		int total = (t-running.get_introduced());
		running.set_tt(total);
		plist[index_process3(plist,len,running.get_id())] = running;
	}
	return 1;
}
