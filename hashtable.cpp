
template<typename K, typename V>
HashTable<K,V>::HashTable(size_t size){
	hashTable.resize(prime_below(size)); 	

	defaultNums = 0;
}



template<typename K, typename V>  
HashTable<K,V>::~HashTable(){


	clear(); 
}






template<typename K, typename V>
bool HashTable<K,V>::contains(const K & k) const{

    size_t index = myhash(k);


for(auto i = hashTable[index].begin(); i != hashTable[index].end(); ++i){

if(i->first == k){

return true; 

}
} 
    return false; 
}




template<typename K, typename V>
bool HashTable<K,V>::remove(const K&k){

size_t index = myhash(k);
    
 
for(auto i = hashTable[index].begin(); i != hashTable[index].end(); ++i){

if(i->first == k){

    hashTable[index].erase(i);


    --defaultNums; 

return true;
}
} 


    return false;
}



template<typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K, V>& kv) const{

auto& sh = hashTable[myhash(kv.first)];
    
	
return find(sh.begin(), sh.end(), kv) != sh.end();
}

template<typename K, typename V> 
bool HashTable<K,V>::insert(const std::pair<K,V> & kv){

    size_t index = myhash(kv.first);
    
   
for (auto& pair : hashTable[index]){


if (pair.first == kv.first){

    pair.second = kv.second; 


return true; 
}
}

 hashTable[index].push_back(kv);  
    ++defaultNums;

if (defaultNums > hashTable.size()){

    rehash();  
}

    return true;
}



template<typename K, typename V>
bool HashTable<K,V>::insert(std::pair<K,V> && kv){

const std::pair<K,V> Pair = std::move(kv);



	return insert(Pair);  
}




template<typename K, typename V> 
void HashTable<K,V>::makeEmpty(){

for(auto &elements:hashTable){

hashTable.clear(); 
}

	defaultNums = 0;
}


template<typename K, typename V>
bool HashTable<K,V>::load(const char* filename){



ifstream inFile(filename);

if (!inFile){
    
    cerr << "Error: Unable to open file " << filename << endl;
    return false;
}

pair<K,V> Pair;

while (inFile >> Pair.first >> Pair.second){

insert(Pair);
}

    return true;
}

template<typename K, typename V>
void HashTable<K,V>::dump() const{


for(int in = 0; in < hashTable.size(); in++){

cout << "v[" << in << "]:";

    
if(!hashTable[in].empty()) 

	for(auto i = hashTable[in].begin(); i != hashTable[in].end(); ++i){

		if(i != hashTable[in].begin())
			cout << ':'; 

			cout << i->first << ' ' << i->second;

}
	cout << endl;
	}
}





template<typename K, typename V>
void HashTable<K,V>::resizeTable(size_t size)
{

if(changeSize()!= size){

hashTable.resize(prime_below(size));	
defaultNums = 0;

}
}



template<typename K, typename V>
bool HashTable<K,V>::write_to_file(const char* filename) const{

std::ofstream os; 

os.open(filename);
	
if(!os){


	return false;
}



for(int h=0; h<hashTable.size();h++){

for(auto i = hashTable[h].begin();i!=hashTable[h].end();++i){

	os << i->first << ' ' << i->second << '\n';
}
}

os.close(); 


return true;
}


template<typename K, typename V>
size_t HashTable<K,V>::myhash(const K & k) const{

static std::hash<K> t;

return t(k) % hashTable.size();
}




template<typename K, typename V>
void HashTable<K,V>::clear(){


	makeEmpty();  
}


template<typename K, typename V>
int HashTable<K,V>::changeSize() const{


return defaultNums;

}


template<typename K, typename V>
void HashTable<K,V>::rehash(){


auto tempOld=hashTable;
	
hashTable.resize(prime_below(2 * hashTable.size()));

for(auto & elements: hashTable)
	elements.clear();	
	defaultNums = 0;

for(auto & elements: tempOld){

		for(auto & Pair:elements) insert(move(Pair));
	}
}






template <typename K, typename V>
unsigned long HashTable<K,V>::prime_below(unsigned long n){
   
const unsigned long max_num = 1000000;

if(n > MAX_ALLOWED)
    {
        std::cerr << "** input too large\n";
        return 0;
    }
    
    if(n <= 1)
    {
        std::cerr << "** input too small\n";
        return 0;
    }

    std::vector <unsigned long> v(n+1);
    setPrimes(v);
    while(n > 2)
    {
        if(v[n] == 1)
            return n;
        --n;
    }

    return 2;
}

template <typename K, typename V>
void HashTable<K,V>::setPrimes(std::vector<unsigned long>& sprimes)
{
  int i = 0;
  int j = 0;

  sprimes[0] = 0;
  sprimes[1] = 0;
  int n = sprimes.capacity();

  for(i = 2; i < n; ++i)
    sprimes[i] = 1;

  for(i = 2; i*i < n; ++i)
    {
      if(sprimes[i] == 1)
        for(j = i + i ; j < n; j += i)
          sprimes[j] = 0;
    }
}

