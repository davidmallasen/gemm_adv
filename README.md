# Advanced general matrix multiplication (gemm) 

First clone this repo by running:

~~~
git clone https://github.com/davidmallasen/gemm_adv.git
cd gemm_adv
~~~

Install googletest and googlemock for unit testing and build OpenBLAS and LIBXSMM to improve the naive implementation.

To build OpenBLAS in Ubuntu download the tar.gz from [OpenBLAS](https://www.openblas.net/), extract it and run `make`. Then run `make PREFIX=/path/to/installation install`.

To build LIBXSMM in Ubuntu download the tar.gz from [GitHub](https://github.com/hfp/libxsmm/releases/), extract it and run `make PREFIX=/path/to/installation STATIC=0 install`.

Detailed steps can be seen in the `Dockerfile`.

Set the following environment variables:
~~~
export OPENBLAS_NUM_THREADS=1
export OPENBLAS_LIB=/path/to/openblas/lib
export OPENBLAS_INCLUDE=/path/to/openblas/include
export LIBXSMM_LIB=/path/to/libxsmm/lib
export LIBXSMM_INCLUDE=/path/to/libxsmm/include
export LD_LIBRARY_PATH=$OPENBLAS_LIB:$LIBXSMM_LIB:$LD_LIBRARY_PATH
~~~
Where `OPENBLAS_LIB` contains `libopenblas.so`, `LIBXSMM_LIB` contains `libxsmm.so`, `OPENBLAS_INCLUDE` contains `cblas.h` and `LIBXSMM_INCLUDE` contains `libxsmm.h`. We set the number of threads to 1 to have a better comparison with the naive implementation.

To build the system, in the root of the repo run:

~~~
./autogen.sh
./configure
make
~~~

## Unit testing

To execute the tests for the naive implementation and the OpenBLAS replacement run `make check`.
To get the full output run `./tests/bin/gemm_test`, `./tests/bin/openblas_gemm_test` or `./tests/bin/libxsmm_gemm_test`.

## Performance comparisons

To measure the performance of the naive, OpenBLAS and LIBXSMM implementations you can run the `measure_performance.sh` script. For example:

~~~
./scripts/measure_performance.sh bin/naive data/naive_perf.dat
./scripts/measure_performance.sh bin/openblas data/openblas_perf.dat
./scripts/measure_performance.sh bin/libxsmm data/libxsmm_perf.dat
~~~

Performance data is given for an intel i7-9750H CPU running on one core. You can visualize the results in the images given or generate new plots using `gnuplot` with the `.gp` files.

*Note:* When using LIBXSMM, the matrices have to be transposed since the library expects column-major order. This could affect the comparison with the other implementations.

## Deploying with docker

First create the distribution tarball by running `make dist`. Or download it from [releases](https://github.com/davidmallasen/gemm_adv/releases/).

Then build and run the docker container:
~~~
sudo docker build -t gemm_adv-1:latest .
sudo docker run --rm -v `pwd`/data:/gemm_adv-1.0/data -it gemm_adv-1:latest
~~~

In the docker container you can run the same tests and performance comparisons as above.
