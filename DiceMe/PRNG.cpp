//PRNG.cpp -- implementation of a random number generator
#pragma once
#include "stdafx.h"
#include "PRNG.h"


#ifndef _PRNG
/* MWC256 
from 
Usenet posting by G. Marsaglia
-
Period 
2^8222

Source code was quoted in "Good Practice in (Pseudo) Random Number Generation for Bioinformatics Applications" by David Jones (d.jones@cs.ucl.ac.uk)
*/
unsigned int MWC256(void)
{
unsigned long long t;
static unsigned char i=255;
t = 809430660ULL * Q[++i] + c;
c = (t>>32);
return (Q[i]=(unsigned int)t);
}

// initQ seeds the array Q with initial values
void initQ()
{
	unsigned *k = new unsigned int;
	for (int i = 0; i < 256; i++)
	{
		rand_s(k);
		Q[i] = *k;
	}
	delete k;
}
#endif