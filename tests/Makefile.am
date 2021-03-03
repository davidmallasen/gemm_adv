check_PROGRAMS = func_test
TESTS = $(check_PROGRAMS)

func_test_SOURCES = test.cpp

func_test_CPPFLAGS = -I$(top_srcdir)/include

func_test_CXXFLAGS = $(GTEST_CFLAGS) $(GMOCK_CFLAGS)

func_test_LDFLAGS = -pthread

func_test_LDADD = $(GTEST_LIBS) \
                  $(GMOCK_LIBS) \
                  $(top_builddir)/src/__top_builddir__bin_main_out-gemm.o
