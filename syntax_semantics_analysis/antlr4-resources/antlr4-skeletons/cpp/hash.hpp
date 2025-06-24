#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include <string>

using namespace std;

inline unsigned int SDBMHash(string str)
{
	unsigned int hash = 0;
	unsigned int len = str.length();

	for (unsigned int i = 0; i < len; i++)
	{
		hash = ((str[i]) + (hash << 6) + (hash << 16) - hash);
	}

	return hash;
}



#endif // HASH_HPP