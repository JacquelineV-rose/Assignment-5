#include "passserver.h"
#include "hashtable.h"



using namespace std;



using namespace cop4530;




PassServer::PassServer(size_t size){


	pServer.resizeTable(size); 

}




bool PassServer::load(const char* filename){


return pServer.load(filename);


}




bool PassServer::addUser(std::pair<string, string> && kv){



pair<string, string> x2(std::move(kv));

return addUser(x2);
}

bool PassServer::removeUser(const string & k){


return pServer.remove(k);
}



bool PassServer::addUser(std::pair<string, string>&kv){

	
string a = encrypt(kv.second);
	

pair<string, string> x2(kv.first,a);

	
return pServer.insert(x2);


}





bool PassServer::changePassword(const pair<string, string> & p, const string & newpassword){

	
if(p.second == newpassword){

		
	return false;
}
else if(!pServer.contains(p.first)){

	return false;

}else{


	string oldPassword = encrypt(p.second);
	string newPassword = encrypt(newpassword);
		
	pair<string, string> vp(p.first, oldPassword);



if(!pServer.match(vp)){


	return false; 

}
else{
		
	pair<string, string> np(p.first, newPassword);

	pServer.insert(np); return true;

}
}
}





bool PassServer::write_to_file(const char* filename) const{



	return pServer.write_to_file(filename);
}



PassServer::~PassServer(){


pServer.clear();
}



string PassServer::encrypt(const string & str){
  
const char* secretMsg = "$1$########";
    
    
    string sEncryption = crypt(str.c_str(), secretMsg);
    
  
    return sEncryption.substr(12);
}




bool PassServer::find(const string & user) const{


	return pServer.contains(user);
}

void PassServer::dump() const{
	


	pServer.dump();

}

size_t PassServer::size() const{



	return pServer.changeSize();
}


