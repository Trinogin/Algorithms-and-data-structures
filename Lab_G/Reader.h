#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<vld.h>

/* Stream to read, num of positions in string */
char* ReadLine(FILE* in, int* n);

#endif //READER_H_INCLUDED