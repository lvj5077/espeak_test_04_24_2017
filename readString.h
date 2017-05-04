#ifndef _READSTRING_H_
#define _READSTRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class ReadString

{
	public:
		ReadString();
		virtual ~ReadString();

		void readStr(char text[]);
};



#endif