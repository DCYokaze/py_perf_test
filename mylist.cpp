#include <Python.h>
#include <vector>

static PyObject* remove_elements(PyObject* self, PyObject* args) {
    int size;
    if (!PyArg_ParseTuple(args, "i", &size)) {
        return NULL;
    }

    std::vector<int> my_list(size);
    for (int i = 0; i < size; ++i) {
        my_list[i] = i + 1;
    }

    while (!my_list.empty()) {
        PyObject* py_list = PyList_New(my_list.size());
        if (!py_list) {
            return NULL;
        }
        for (size_t i = 0; i < my_list.size(); ++i) {
            PyObject* num = PyLong_FromLong(my_list[i]);
            if (!num) {
                Py_DECREF(py_list);
                return NULL;
            }
            PyList_SET_ITEM(py_list, i, num);
        }
        PyObject_Print(py_list, stdout, 0);
        printf("\n");
        Py_DECREF(py_list);

        int removed_element = my_list.front();
        my_list.erase(my_list.begin());
        printf("Removed element: %d\n", removed_element);
    }

    Py_RETURN_NONE;
}

static PyMethodDef methods[] = {
    {"remove_elements", remove_elements, METH_VARARGS, "Remove elements from a list."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "mylist",   // Module name
    NULL,       // Documentation
    -1,         // Size of per-interpreter state of the module
    methods     // Method table
};

PyMODINIT_FUNC PyInit_mylist(void) {
    return PyModule_Create(&module);
}

