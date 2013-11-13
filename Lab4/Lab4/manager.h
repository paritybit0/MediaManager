#ifndef MANAGER_H
#define MANAGER_H
#include "customerindex.h"
#include "productcollection.h"
#include "commandfactory.h"
#include "productfactory.h"
#include "error.h"
#include <string>

/*
The manager class is the main controller for the program.
*/

class Manager{

private:
    CustomerIndex customerDB;
    ProductCollection productDB;
    CommandFactory cFactory;
    ProductFactory mFactory;

public:
	Manager(); //Initializes all collections and factories
	~Manager();
	
	bool inputProduct(std::string);
    bool inputCustomer(std::string);
    bool inputCmd(std::string);
	 // {    // pseudocode for inputCmd
     //     Command CMD = CommandFactory.create(arg)
     //     cmd.execute
     //     delete cmd
     // }
};

#endif