#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


void MenuHeader() {
	for (int i = 0; i < 50; ++i) {
		cout << '-';
	}

	cout << endl;

	cout << "|" << setw(27) << "Main Menu" << setw(22) << "|" << endl;

	for (int i = 0; i < 50; ++i) {
		cout << '-';
	}

	cout << endl;
}




/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("mod7");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();


	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc1(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"mod7");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"printme");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


void MenuDisplay() {

	int usrChoice;
	string choice;

	MenuHeader();

	cout << "|" << "1. All items purchase info" << setw(23) << "|" << endl;
	cout << "|" << "2. Specific item purchase info" << setw(19) << "|" << endl;
	cout << "|" << "3. Histogram of sales" << setw(28) << "|" << endl;
	cout << "|" << "4. Exit" << setw(42) << "|" << endl;

	for (int i = 0; i < 50; ++i) {
		cout << '-';
	}

	cout << "\n\nEnter option (1-4): ";
	cin >> usrChoice;


	switch (usrChoice) {
	case 1:
		//all items
		CallProcedure("printsomething");
		cout << "Press enter to continue..";
		cin.ignore();
		cin.ignore();
		MenuDisplay();
	case 2:
		//specific item
		cout << "Enter item: ";
		cin >> choice;
		cout << callIntFunc1("PrintMe", choice);
		cout << "Press enter to continue..";
		cin.ignore();
		cin.ignore();
		MenuDisplay();
	case 3:
		//histogram

	case 4:
		break;
	default:
		cout << "Please enter a number 1-4 .. press enter to continue" << endl;
		cin.ignore();
		cin.ignore();
		MenuDisplay();
	}

	//option 1 list items purchased on given day
	//option 2 list number of times given object purchased on given day
	//option 3 histogram
	//option 4 exit
}



int main()
{
	MenuDisplay();

}