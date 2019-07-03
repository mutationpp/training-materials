
# Change this path to your Mutation++ install path
MUTATIONPP_INSTALL = $(MPP_DIRECTORY)/install

CXX_FLAGS = -I $(MUTATIONPP_INSTALL)/include \
			-I $(MUTATIONPP_INSTALL)/include/mutation++ \
			-I $(MPP_DIRECTORY)/thirdparty/eigen \
 			-O3 -std=c++11

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

