#include "Process.h"
#include "FIFO.h"
#include "SJF.h"
#include "SRT.h"
#include "MLF.h"
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>

int printline(Process * plist, int pcount){
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	float avg = 0;
	int i = 0;
	while (i<pcount){
		avg += plist[i].get_total_time();
		i++;
	}
	avg = (avg/pcount);
	std::cout << avg << " ";
	i = 0;
	int first = 1;
	while (i<pcount){
		if (first){
			first = 0;
			std::cout << plist[i].get_total_time();
		}
		else{
			std::cout << " " << plist[i].get_total_time();
		}
		i++;
	}
	return 1;
}

int main(){
	std::string buff;
	std::getline(std::cin,buff);
	char cbuff[1024];
	std::strcpy (cbuff, buff.c_str());
	char * iter = std::strtok (cbuff, " ");
	int arrival = 1;
	int arrive;
	int req;
	Process plist[20];
	int pcount = 0;
	int id = 0;
	while (iter != 0){
		if (arrival){
			arrival = 0;
			arrive = atoi(iter);
			iter = std::strtok(NULL," ");
		}
		else{
			arrival = 1;
			req = atoi(iter);
			Process x(arrive, req, id);
			id++;
			plist[pcount] = x;
			pcount++;
			iter = std::strtok(NULL," ");
		}
	}
	//plist created
	
	Process plist1[20];
	Process plist2[20];
	Process plist3[20];
	Process plist4[20];
	int i = 0;
	while (i < pcount){
		plist1[i] = plist[i];
		plist2[i] = plist[i];
		plist3[i] = plist[i];
		plist4[i] = plist[i];
		i++;
	}
	//FIFO
	//std::cout << "starting FIFO" << std::endl;//debug
	FIFO(plist1, pcount);
	printline(plist1, pcount);
	std::cout << std::endl;
	//SJF
	//std::cout << "starting SJF" << std::endl;//debug
	SJF(plist2, pcount);
	printline(plist2, pcount);
	std::cout << std::endl;
	//SRT
	SRT(plist3, pcount);
	printline(plist3, pcount);
	std::cout << std::endl;
	//MLF
	MLF(plist4, pcount);
	printline(plist4, pcount);
	std::cout<<std::endl;
	return 0;
}
