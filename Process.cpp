#include "Process.h"

Process::Process(int intro, int req, int id1){
	required = req;
	remaining = req;
	introduced = intro;
	total_time = -1;
	id = id1;
	slice = 0;
}

Process::Process(){
	required = 0;
	remaining = 0;
	introduced = 0;
	total_time = -1;
	id = -1;
	slice = 0;
}

int Process::get_required() const {return required;}

int Process::get_remaining() const {return remaining;}

int Process::get_introduced() const {return introduced;}

int Process::get_total_time() const {return total_time;}

int Process::get_id() const {return id;}

int Process::dec_remaining(){
	remaining = remaining - 1;
	return remaining;
}

int Process::set_tt(int set){
	total_time = set;
	return total_time;
}

int Process::get_slice() const {return slice;}
int Process::set_slice(int i){
	slice = i;
	return slice;
}
int Process::dec_slice(){
	slice = slice -1;
	return slice;
}
