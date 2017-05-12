# c-extension-python
Toy application in which C Extensions are converted in Python Module without using SWIG

Run the following command whenever you change the file ex.c which contains C-functions which are to be wrapped and used in Python <br>

```
sudo python setup.py install
```

The module is named as helloworld and the function which we have wrarpped is sinusoidOfTwoAngles, it takes two C-double variables as input and outputs a C-double variable <br>
Import the module's function as below

```
from helloworld import *
```
