
# Change this path to your Mutation++ install path
MUTATIONPP_INSTALL = $(MPP_DIRECTORY)/install

CXX_FLAGS = -I $(MUTATIONPP_INSTALL)/include \
			-I $(MUTATIONPP_INSTALL)/include/mutation++ \
			-I $(MPP_DIRECTORY)/thirdparty/eigen \
 			-O3 -std=c++11

# use .dylib for Mac, .so for Unix
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CXX      = g++
	CXX_LIBS = $(MUTATIONPP_INSTALL)/lib/libmutation++.so
endif
ifeq ($(UNAME_S),Darwin)
	CXX      = c++
	CXX_LIBS = $(MUTATIONPP_INSTALL)/lib/libmutation++.dylib
endif

all : mixture_options

mixture_options : mixture_options.o
	$(CXX) -o $@ $(CXX_FLAGS) $^ $(CXX_LIBS)

%.o : %.cpp
	$(CXX) -c $(CXX_FLAGS) $<

