#ifndef HASHTABLE_H
#define HASHTABLE_H




#include<iostream>
#include<list> 
#include<fstream> 
#include<algorithm>
#include<vector> 







using namespace std;
namespace cop4530
{

template<typename K, typename V>

class HashTable{

public:


explicit HashTable(size_t size = 101);


~HashTable(); 
bool contains(const K & k) const; 

bool match(const std::pair<K, V> &kv) const;

bool insert(const std::pair<K, V> & kv); 

bool insert (std::pair<K, V> && kv);
bool remove(const K & k); 

void clear(); 

bool load(const char *filename); 

void dump() const;




            
            
bool write_to_file(const char *filename) const; 
    		
int changeSize() const;
void resizeTable(size_t size);
private:
           
           
void makeEmpty(); 

void rehash(); 
size_t myhash(const K &k) const; 



unsigned long prime_below (unsigned long); 
void setPrimes(std::vector<unsigned long>&);



int defaultNums; 

vector<list<pair<K,V>>> hashTable;
};









#include "hashtable.hpp"
}  

#endif
