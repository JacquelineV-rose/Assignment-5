#include<iostream>

#include "passserver.h"
#include "hashtable.h"



using namespace std;







void jump();
void Menu();

int main()
{
    
    
cout << "Enter preferred hash table capacity: ";

int inputCapacity;
cin >> inputCapacity;




PassServer x(inputCapacity);





char userInput;



do{
  
Menu();

cin >> userInput;





switch(userInput){

case 'l': {

string filename;
cout << "Enter password file name to load from: ";

jump();
getline(cin, filename);
                
if(!x.load(filename.c_str())){

cout << "Could not open file " << filename << endl;
}


break;
}

case 'a': {

string name, addu;
cout << "Enter username: ";

jump();
getline(cin, name);



cout << "Enter password: \n";
jump();
getline(cin, addu);
                
pair<string, string> newPair(name, addu);
                
if(x.addUser(newPair)){


  cout << "User: " << name << " added.\n";


} 
else{

cout << "*****Error: User already exists. Could not add user.\n";
}


break;
}

case 'r': {

string name;

cout << "Enter username: ";

jump();
getline(cin, name);

if(x.removeUser(name)){

cout << "User: " << name << " deleted.\n";
} 
else{

cout << "*****Error: User not found. Could not delete user.\n";
}

break;
}

case 'c': {
string name;

string newPass;
string oldPass;
                
cout << "Enter username: ";    
jump();
getline(cin, name);  



cout << "Please enter password: \n";    
jump();
getline(cin, oldPass);


cout << "Please enter new password: "; 

jump();
getline(cin, newPass);
                
pair<string, string> oldPair(name, oldPass);



if(x.changePassword(oldPair, newPass)){

cout << "Password changed for user " << name << '\n';

} 
else{

cout << "*****Error: Could not change user password." << endl;
}

break;

}

case 'f': {

string name;
cout << "Enter username: ";


jump();
getline(cin, name);
                
if(x.find(name)){


cout << "User " << name << " found.\n";
}
else{

cout << "User '" << name << "' not found." << endl;
}

break;
}

case 'd': {


x.dump();
break;
}

case 's': {

cout << "Size of hashtable: " << x.size() << '\n';
break;

}


case 'w': {
  
string newName;

cout << "Enter password file name to write to: "; 
jump();
                
getline(cin, newName);
x.write_to_file(newName.c_str());

break;

}

case 'x':
                
break;



default:
cout << "*****Error: Invalid entry. Try again." << endl;
break;


}


}
while(userInput != 'x');










return 0;
}


void jump(){


char jmp;

while(isspace(cin.peek()) && !cin.eof()){


cin.ignore();

}
}

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter inp : ";
}
