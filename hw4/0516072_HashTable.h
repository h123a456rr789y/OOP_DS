#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <list>

using namespace std;

struct HGW{
    string Key;
    string Gender;
    int Weight;
    int Height;
    string getGender(){return Gender;}
    int getHeight(){return Height;}
    int getWeight(){return Weight;}
    struct HGW *next;
};

class HashTable{
public:
    HashTable();
    //~HashTable();
    struct HGW operator[](string);
    void addItem(string,string,int,int);
    int FindHash(string);


private:
    HGW* hgw;
};



#endif // 0516072_HASHTABLE_H_INCLUDED
