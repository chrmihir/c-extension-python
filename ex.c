#include <Python.h>
#include <math.h>

double sinusoidOfTwoFunctions(double angle1, double angle2) {
	return sin(angle2 + angle1);
}

static PyObject* helloworld(PyObject* self, PyObject* args) {
	double angle1, angle2;
	/*
	if(PyArg_ParseSize() != 2)
		return Py_Return_None;
	*/
	if(PyTuple_Size(args) != 2)
		return Py_BuildValue("s", "Expected 2 arguments");
	PyArg_ParseTuple(args,"dd", &angle1, &angle2);
	double answer = sinusoidOfTwoFunctions(angle1, angle2);
	return PyFloat_FromDouble(answer);
}

/* Array of structs which are nothing but the methods this module supports */
/* Struct looks like name, function pointer, flags, docstring */

static PyMethodDef helloworld_methods[] = {
	/* For a particular element of the above array
		First entry is the method name which will be callled from function 
		Second entry is the function pointer, the actual function which we are integrating in Python 
		Third entry is information about the arguments which our C-function requires
		Fourth entry is the documentation string, if at all we need to document it
	*/
	{ "sinusoidOfTwoFunctions", (PyCFunction) helloworld, METH_VARARGS, NULL },
	{ NULL, NULL, 0, NULL}				/* Shows end of the entries of array */
};

/* After init put the module-name */
/* We don't want to put any docstring */

void inithelloworld(void) {
	Py_InitModule3("helloworld", helloworld_methods, NULL);
}
