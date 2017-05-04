#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include "readString.h"
#include <iostream>
//-----------------------------------------------
using namespace std;


int main(void){
	
	ReadString myRead;
	struct timespec start, finish;
	double elapsed;
	int countN = 1;

	clock_gettime(CLOCK_MONOTONIC, &start);
	sleep(2);

	clock_gettime(CLOCK_MONOTONIC, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	std::cout << "sleeped "<< elapsed << std::endl;

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i =0;i<countN;i++){
		char text[] = " If we are thrown into the blazing furnace, the God we serve is able to deliver us from it, and he will deliver us from Your Majesty’s hand. ";
		myRead.readStr(text);
	}
/////////////////////////////////////////////
	cout << "I am here!" <<endl;
	for (int i=0;i<6;i++){
		sleep(1);
		cout <<"counting " << i <<endl;
	}
/////////////////////////////////////////////
	clock_gettime(CLOCK_MONOTONIC, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	std::cout << "elapsed by function: "<<elapsed/countN << std::endl;

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i =0;i<countN;i++){
		char text[] = " If we are thrown into the blazing furnace, the God we serve is able to deliver us from it, and he will deliver us from Your Majesty’s hand. ";
		std::cout << text <<std::endl;
		// printf("'%s'",str);
	}
	clock_gettime(CLOCK_MONOTONIC, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	std::cout << "elapsed by printing: "<<elapsed/countN << std::endl;


	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i =0;i<countN;i++){
		string str=" If we are thrown into the blazing furnace, the God we serve is able to deliver us from it, and he will deliver us from Your Majesty’s hand. ";
		// system("espeak 'hello world'");
		string cmd = "espeak '"+ str +"'";
		int systemRet = system(cmd.c_str());
		if(systemRet == -1){
			std::cout << "system failed"<<std::endl;
		}	
	}
	clock_gettime(CLOCK_MONOTONIC, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	std::cout << "elapsed by system: "<<elapsed/countN << std::endl;


	pid_t pid = fork();
	char text[] = " If we are thrown into the blazing furnace, the God we serve is able to deliver us from it, and he will deliver us from Your Majesty’s hand. ";
	if (pid == 0)
    {
		myRead.readStr(text);
    }
    else if (pid > 0)
    {
		cout << "I am here!" <<endl;
		for (int i=0;i<6;i++){
			sleep(1);
			cout <<"counting " << i <<endl;
		}
    }
    else
    {	
        printf("fork() failed!\n");
        return 1;
    }

	return 0;
}