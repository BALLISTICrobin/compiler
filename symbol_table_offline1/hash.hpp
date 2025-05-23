#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include <string>

using namespace std;

unsigned int SDBMHash(string str, unsigned int num_buckets)
{
	unsigned int hash = 0;
	unsigned int len = str.length();

	for (unsigned int i = 0; i < len; i++)
	{
		hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) %
			   num_buckets;
	}

	return hash;
}

unsigned int DJB2Hash(string str, unsigned int num_buckets)
{
    unsigned int hash = 5381;
    unsigned int len = str.length();

    for (unsigned int i = 0; i < len; i++)
    {
        hash = ((hash << 5) + hash + str[i]) % num_buckets;  // hash * 33 + c
    }

    return hash;
}

unsigned int FNVHash(string str, unsigned int num_buckets)
{
    const unsigned int FNV_prime = 16777619;
    unsigned int hash = 2166136261;
    unsigned int len = str.length();

    for (unsigned int i = 0; i < len; i++)
    {
        hash = (hash * FNV_prime) ^ str[i];
    }

    unsigned int bucket = hash % num_buckets;

    return bucket;
}



#endif // HASH_HPP