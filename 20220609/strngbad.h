#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class CStringBad
{
private:
	char* str;
	int len;
	static int num_strings;

public:
	CStringBad(const char* s);
	CStringBad();
	~CStringBad();

	friend std::ostream& operator<<(std::ostream& os, const CStringBad& st);
};

#endif