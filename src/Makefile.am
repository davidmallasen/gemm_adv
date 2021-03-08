# 1. specify the executable target in bin
bin_PROGRAMS = $(top_builddir)/bin/naive $(top_builddir)/bin/openblas $(top_builddir)/bin/libxsmm

# 2. specify source file (in this directory)
__top_builddir__bin_naive_SOURCES = main.c gemm.c
__top_builddir__bin_openblas_SOURCES = main.c gemm_cblas.c
__top_builddir__bin_libxsmm_SOURCES = main.c gemm_libxsmm.c

# 3. specify the compiler flags
__top_builddir__bin_naive_CFLAGS = -I$(top_builddir)/include -Wall -g -O3
__top_builddir__bin_openblas_CFLAGS = -I$(top_builddir)/include -I$(OPENBLAS_INCLUDE) -Wall -g -O3
__top_builddir__bin_libxsmm_CFLAGS = -I$(top_builddir)/include -I$(LIBXSMM_INCLUDE) -Wall -g -O3

__top_builddir__bin_openblas_LDADD = -L$(OPENBLAS_LIB) -lopenblas -lpthread
__top_builddir__bin_libxsmm_LDADD = -L$(LIBXSMM_LIB) -L$(OPENBLAS_LIB) -lxsmm -lopenblas
