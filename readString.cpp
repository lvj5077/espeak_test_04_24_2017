#include "readString.h"

ReadString::ReadString(){}
ReadString::~ReadString(){}

void ReadString::readStr(char text[]){
	char sys_text[strlen(text)+15];
	memset(&sys_text[0], 0, sizeof(sys_text));       
//-----------------------------------------------------------
	strcpy (sys_text,"espeak -ven '\''");                          
	strcat (sys_text,text);
	strcat (sys_text,"'\''");
	system(sys_text);
}