#include <Python.h>
#include "PythonQt.h"
#include <iostream>
using namespace std;

class Foo
{
public:
    Foo()
    {
        x = PyDict_New();
    }

    ~Foo()
    {
        Py_DECREF(x);
    }
    void process()
    {
        PyDict_Clear(x);
        //for (int i=0; i<100;i++)
        //{
            PyObject *key, *val;
            //for (int j=0; j<2; j++)
            //{
                for ( int i=0; i<10; i++ )
                {
                    PyObject *key =  PyInt_FromLong(i);
                    PyObject *val = PyInt_FromLong(i);
                    PyDict_SetItem(this->x,key,val);
                    Py_DECREF(key);
                    Py_DECREF(val);
                }
            //}
       // }
    }

private:
    PyObject *x;

};

int main()
{
    Py_Initialize();
    Foo *foo = new Foo();
    foo->process();
    delete foo;
    Py_Finalize();

    return 0;
}
