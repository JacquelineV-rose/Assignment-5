#include <iostream>
#include <string>
#include "Assign5.h"
#include <cmath>
using namespace std;

//========SHAPES=========
Shape::~Shape(){

}

double Shape::getPerimeter() const{

cout << "Nothing to see here!" << endl;
return 0.0;

}

double Shape::getArea() const{

cout << "Nothing to see here either X.X" << endl;
return 0.0;  
}

//=======================


//========SQUARE=========

Square::Square(double s){

side = s;

}

double Square::getPerimeter() const{

return 4 * side;    
}

double Square::getArea() const{
return side * side;    
}
//==============================


//===========Circle=============

Circle::Circle(double r){

radius = r;    
}

double Circle::getPerimeter() const{

return 2 * 3.14 * radius;

}

double Circle::getArea() const{

return 3.14 * radius * radius;    
}
//============================

//========Triangle===========

Triangle::Triangle(double a, double b, double c){
side1 = a;
side2 = b;
side3 = c;

}

double Triangle::getPerimeter() const{

return side1 + side2 + side3;
}

double Triangle::getArea() const{

double x = (side1 + side2 + side3)/2;
double a = sqrt(x* (x - side1) * (x - side2) * (x - side3));
return a;
}

//=========================

//======The driver========


void menuDriver::menuDisplay() const{
cout << "Hello, welcome to the shape program. Please select which shape to add by selecting the corresponding number." << endl;
cout << "1. Add square" << endl;
cout << "2. Add circle" << endl;
cout << "3. Add triangle" << endl;
cout << "4. Compute the aggregated area of all shapes" << endl;
cout << "5. Compute the perimeter of all shapes." << endl;
cout << "6. Exit" << endl;

}



void menuDriver::runProgram(){
int choice;
int size = 0;

const int index = 5;  

Shape** shapes = new Shape*[index]; 
int capacity = index;  


do {
menuDisplay();
cout << "Please enter number here: " << endl;
cin >> choice;

switch (choice) {
case 1: {
double side;
cout << "Enter the side length of the square: ";
cin >> side;

if (size == capacity) {
capacity *= 2;
Shape** newShapes = new Shape*[capacity];
for (int i = 0; i < size; ++i) {
newShapes[i] = shapes[i];
}
delete[] shapes;
shapes = newShapes;
}
shapes[size++] = new Square(side);

//Displaying your values
cout << "Squares area: " << shapes[size - 1]->getArea() << endl;
cout << "Squares perimeter: " << shapes[size - 1]->getPerimeter() << endl;

break;
}


case 2: {
double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    
if (size == capacity) {
capacity *= 2;
Shape** newShapes = new Shape*[capacity];
for (int i = 0; i < size; ++i) {
newShapes[i] = shapes[i];
}
delete[] shapes;
shapes = newShapes;
}
shapes[size++] = new Circle(radius);

cout << "Circles area: " << shapes[size - 1]->getArea() << endl;
cout << "Circles perimeter: " << shapes[size - 1]->getPerimeter() << endl;


break;

}


case 3: {
double side1, side2, side3;
cout << "Enter side 1 of the triangle: " << endl;
cin >> side1;

cout << "Enter side 2 of the triangle: " << endl;
cin >> side2;
            
cout << "Enter side 3 of the triangle: " << endl;
cin >> side3;

if (size == capacity) {

capacity *= 2;
Shape** newShapes = new Shape*[capacity];
for (int i = 0; i < size; ++i) {
newShapes[i] = shapes[i];
}
delete[] shapes;
shapes = newShapes;
}
shapes[size++] = new Triangle(side1, side2, side3);

cout << "Triangles area: " << shapes[size - 1]->getArea() << endl;
cout << "Triangles perimeter: " << shapes[size - 1]->getPerimeter() << endl;


break;
}

case 4: {
double totalArea = 0.0;
for (int i = 0; i < size; ++i) {
totalArea += shapes[i]->getArea();
}
cout << "Aggregate area of all shapes is: " << totalArea << endl;
break;
}

case 5:
{
double totalPerimeter = 0.0;
for (int i = 0; i < size; ++i) {

totalPerimeter += shapes[i]->getPerimeter();
}
cout << "The aggregated perimeter of all shapes is: " << totalPerimeter << endl;
break;
}

case 6:
cout << "Exiting program." << endl;
break;

default:
cout << "Invalid choice. Please try again." << endl;
}

} while (choice != 6);

   
for (int i = 0; i < size; ++i) {
delete shapes[i];
}
delete[] shapes;
}




