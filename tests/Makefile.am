check_PROGRAMS = bin/gemm_test bin/openblas_gemm_test
TESTS = $(check_PROGRAMS)

bin_gemm_test_SOURCES = gemm_test.cpp
bin_openblas_gemm_test_SOURCES = gemm_test.cpp

bin_gemm_test_CPPFLAGS = -I$(top_srcdir)/include
bin_openblas_gemm_test_CPPFLAGS = -I$(top_srcdir)/include -I$(OPENBLAS_INCLUDE)

bin_gemm_test_CXXFLAGS = $(GTEST_CFLAGS) $(GMOCK_CFLAGS)
bin_openblas_gemm_test_CXXFLAGS = $(GTEST_CFLAGS) $(GMOCK_CFLAGS)

bin_gemm_test_LDFLAGS = -pthread
bin_openblas_gemm_test_LDFLAGS = -pthread

bin_gemm_test_LDADD = $(GTEST_LIBS) \
                      $(GMOCK_LIBS) \
                      $(top_builddir)/src/__top_builddir__bin_naive-gemm.o
bin_openblas_gemm_test_LDADD = $(GTEST_LIBS) \
                               $(GMOCK_LIBS) \
                               $(top_builddir)/src/__top_builddir__bin_openblas-gemm_cblas.o \
                               -L$(OPENBLAS_LIB) -lopenblas -lpthread
