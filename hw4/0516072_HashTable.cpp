#include "0516072_HashTable.h"


HashTable::HashTable(){
    hgw = new struct HGW [10000];
	for(int i=0; i<10000; i++){
		hgw[i].Weight = 0;
		hgw[i].Height = 0;
		hgw[i].next = NULL;
	}
}

struct HGW HashTable::operator[](string key){
    int keynumber=FindHash(key);
    list<HGW>::iterator i;
    struct HGW *ptr=&hgw[keynumber];
    for(;ptr->Key!=key;ptr=ptr->next);
    return *ptr;
};

void HashTable::addItem(string key,string gender,int height,int weight){
    struct HGW *ptr;
	struct HGW *new_node = new struct HGW;
	int keynumber= FindHash(key);
	ptr = &hgw[keynumber];
	while(ptr->Key[0]!='\0' && (ptr->Key)!=key)
		ptr = ptr->next;
	ptr->Key = key;
	ptr->Gender = gender;
	ptr->Height = height;
	ptr->Weight = weight;
	ptr->next = new_node;
	new_node->next = NULL;
}
int HashTable::FindHash(string key){
    int tmp;
    char* c=&key[0];
    tmp= atoi(c);
    return tmp%10000;
}



