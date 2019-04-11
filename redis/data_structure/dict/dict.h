#include <iostream>
//#pragma once
#ifndef __DICT_H
#define __DICT_H
namespace redis{
	
	typedef struct dictEntry{
		void* key;
		union{
			void* value;
			int u32;
		};
		dictEntry *next;
	}dictEntry;

	typedef struct dictTable{
		dictEntry** table;
		int used;
		int mask_index;
		int size;
	}dictTable;

	typedef struct dictType{
		int (*hashFunction)(const void*);
	}dictType;

	typedef struct dict{
		dictTable[2] ht;
		int rehash_index;
		dictType *type;
		void *privdata;
	}dict;

	// api
	dict* dictCreate(void* privdata, dictType* type);
	int dictAdd(dict *d, void *key, void *value);
	int dictDelete(dict *d, const void *key);
	int dictExpand(dict *d, int size);
}
