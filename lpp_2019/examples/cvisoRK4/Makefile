
# Change this path to your Mutation++ install path
MUTATIONPP_INSTALL = $(MPP_DIRECTORY)/install

FC_FLAGS = -J $(MUTATIONPP_INSTALL)/include/mutation++ \
           -O3 -g -fdefault-real-8

# use .dylib for Mac, .so for Unix
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FC       = gfortran
	FC_LIBS = $(MUTATIONPP_INSTALL)/lib/libmutation++_fortran.so
endif
ifeq ($(UNAME_S),Darwin)
	FC       = gfortran
	FC_LIBS = $(MUTATIONPP_INSTALL)/lib/libmutation++_fortran.dylib
endif

cvisoRK4 : cvisoRK4.o
	$(FC) -o $@ $(FC_FLAGS) $^ $(FC_LIBS)

%.o : %.f90
	$(FC) -c $(FC_FLAGS) $<

