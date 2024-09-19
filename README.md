# Matrix library in C

A simple matrix library for use in C. The intended use of this library is for ML workloads.

The format of this library is inspired by [this page](https://itnext.io/tutorial-generics-in-c-b3362b3376a3). While it may be a bit opaque at first glance, using "generics" here makes creating multiple Matrix types incredibly simple.

My original usecase revolves around storing the data from the MNIST dataset and creating a small neural network to predict image contents.

## How to use Matrix

Due to the "generic" nature of this code, its use method may feel a bit nonstandard. I strongly encourage referencing the `tests.h` and `tests.c` files for concrete examples.

In a nutshell, your header files that use Matrix should use the following format:

### Header format

*header.h:*
```
/* Standard dependencies */
#include <standard libraries>
...
/* Matrix definition */
#define MATRIX_CREATE_HEADER
#define MATRIX_TYPE_NAME pixelMatrix
#define MATRIX_TYPE float
#include "Matrix.h"
```

Notice three required definitions: `MATRIX_CREATE_HEADER`, `MATRIX_TYPE_NAME`, and `MATRIX_TYPE`. In order to trigger the creation of the Matrix header (and avoid duplication in later `#include`) `MATRIX_CREATE_HEADER` must be defined. It is `#undef` at the end of `Matrix.h`

`MATRIX_TYPE_NAME` is simply the name you'd like to use for the new Matrix. It can be whatever you want. Since I'm using this specifically with MNIST, creating a Matrix type to store pixel data made sense for me.

`MATRIX_TYPE` is the underlying data type used for the Matrix. While this theoretically could be **any** type, I have only accounted for numerical types. I've tested with `int` and `float` in particular.

### Code format

*code.c*
```
#include "header.h"

// Include the type of Matrix that we want to use
#define MATRIX_TYPE_NAME pixelMatrix
#define MATRIX_TYPE float
#define MATRIX_STRING "%1.3f"
#include "Matrix.c"
```

For the most part, this definition looks the same. Some important differences are the inclusion of `MATRIX_STRING` which is simply the string format to use for your data. While I think I could've found a more elegant solution, this worked well enough for me.

**Notice** that we have an `#include "Matrix.c"` line at the end. This ensures that `Matrix.c` has its macros expand properly at compile time. Do **NOT** include `Matrix.c` in your gcc / clang step!

### Compilation Time

As mentioned previously, do **NOT** include `Matrix.c` when compiling, as it is already referenced in other files with the proper values.

To compile the tests, for example, use something along the lines of `cc --std=c11 tests.c -o target/tests`, where `tests.c` already has `#include "Matrix.c` 

## Tests

Executing `make` will build a basic test suite for Matrix.

## Notes

This has been a great exercise for me to get back into being 'hands-on' and learning more about ML/AI. The approaches I've taken are guaranteed to be naive and I'd love feedback from the community.

If you see something that could be enhanced, please go ahead and create a PR.