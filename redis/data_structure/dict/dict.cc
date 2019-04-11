#include <iostream>
#include <malloc.h>
#include "dict.h"
using namespace std;
using namespace redis;

static int MIN_DICT_LEN = 4;

dict* dictCreate(dictType *type, void *privdata){
	dict* d = (dict*) malloc(sizeof(*d));
	_dictInit(d, type, privdata);
	return d;
}

int _dictInit(dict* d, dictType* type, void *privdata){
	_dictReset(&d->ht[0]);
	_dictReset(&d->ht[1]);
	d->rehash_index = -1;
	d->type = type;
	d->privdata = privdata;
	return 0;
}

void _dictReset(dictTable *ht){
	ht->table = NULL;
	ht->used = 0;
	ht->mask_index = 0;
	ht->size = 0;
}



