#ifndef SEARCH_HEADER_INCLUDED
#define SEARCH_HEADER_INCLUDED

#pragma once

int PalSubSeq(int left, int right, char* str, int** L);

void PalChars(int left, int right, int palLeft, int palRight, char* str, char* res, int**L);

void inStringPalindromeSearch(int n, char* str, char* res, int** L);
#endif //SEARCH_HEADER_INCLUDED
