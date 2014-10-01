#include "calc.h"
#include <string.h>

const char *const name[] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven",
	"eight", "nine", "ten", "eleven", "twelve", "thirteen",
	"fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
	"nineteen"
};

const char *const tname[] = {
	"0", "1", "twenty", "thirty", "forty", "fifty", "sixty",
	"seventy", "eighty", "ninety"
};

const char *const bigname[] = {
	"0", "thousand", "million", "billion"
};


void smallitow(int n, char *s)
{
	if (n>99) {
		int hundreds = n/100;
		n -= hundreds*100;
		strcat(s, name[hundreds]);
		strcat(s, " hundred");
		if (n>0) strcat(s, " ");
	}
	if (n>0) {
		if (n<20) { 
			strcat(s, name[n]);
		}
		else {
			int tens = n/10;
			n -= tens*10;
			strcat(s, tname[tens]);
			if (n>0) {
				strcat(s, "-");
				strcat(s, name[n]);
			}
		}
	}
}

const char *itow(int n)
{
	static char buf[256];
	char *s = buf;

	if (n==0)
		return "zero";

	*s = '\0';
	if (n<0) {
		strcat(s, "negative ");
		n = -n;
	}

	for (int base=1000000000, basename=3; base>=1; base/=1000, basename--) {
		int triple = n/base;
		n -= triple*base;
		if (triple>0) {
			smallitow(triple, s);
			if (basename>=1) {
				strcat(s, " ");
				strcat(s, bigname[basename]);
				if (n>0) strcat(s, " ");
			}
		}
	}

	return s;
}

const char *words_output(int /* base */, number num, int /* width */)
{

	return itow((long) num);
}

static func_info fi(set_current_mode, "words", "english words mode", words_output);
