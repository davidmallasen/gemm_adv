# Advanced general matrix multiplication (gemm) 

First clone this repo by running:

~~~
git clone https://github.com/davidmallasen/gemm_adv.git
cd gemm_adv
~~~

Install googletest and googlemock for unit testing and build OpenBLAS to improve the naive implementation.

To build OpenBLAS in Ubuntu download the tar.gz from [OpenBLAS](https://www.openblas.net/), extract it and run `make`. Then run `make PREFIX=/path/to/installation install`.

Set the following environment variables:
~~~
export OPENBLAS_NUM_THREADS=1
export OPENBLAS_LIB=/path/to/openblas/lib
export OPENBLAS_INCLUDE=/path/to/openblas/include
~~~
Where `OPENBLAS_LIB` contains `libopenblas.a` and `OPENBLAS_INCLUDE` contains `cblas.h`. We set the number of threads to 1 to have a better comparison with the naive implementation.

To build the system, in the root of the repo run:

~~~
./autogen.sh
./configure
make
~~~

## Unit testing

To execute the tests for the naive implementation and the OpenBLAS replacement run `make check`.
To get the full output run `./tests/bin/gemm_test` or `./tests/bin/openblas_gemm_test`.

## Comparison with OpenBLAS

To measure the performance of the naive and OpenBLAS implementations you can run the `measure_performance.sh` script. For example:

~~~
./measure_performance.sh bin/naive data/naive_perf.dat
./measure_performance.sh bin/openblas data/openblas_perf.dat
~~~

Performance data is given for a intel i7-9750H CPU running on one core. You can visualize the results in the images given or generate new plots using `gnuplot` with the `.gp` files.
