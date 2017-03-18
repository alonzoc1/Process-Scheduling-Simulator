#ifndef PROCESS_H
#define PROCESS_H

class Process{
private:
	int required;
	int remaining;
	int introduced;
	int total_time;
	int id;
	int slice;
public:
	Process(int intro, int req, int id1);
	Process();
	int get_required() const;
	int get_remaining() const;
	int get_introduced() const;
	int get_total_time() const;
	int get_id() const;
	int get_slice() const;
	int dec_remaining();
	int set_tt(int set);
	int dec_slice();
	int set_slice(int i);
};
#endif
