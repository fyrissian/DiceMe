//PRNG.h -- declarations and definitions for PRNG.cpp
#pragma once

static unsigned int Q[256];
static unsigned int c=362436;

unsigned int MWC256(void);
void initQ(void);
