// C Program to demonstrate calling 
// a function before declaration 
#include <stdio.h> 

// Main starts 
int main() 
{ 
	// fun() is called before its 
	// declaration/definition 
	fun(); 
} 

// Function Declaration 
int fun() 
{ 
	printf("Hello"); 
	return 0; 
}

