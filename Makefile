#Template Makefile for a simple executable created from a single cxx file and linked with the root librariess

MYMAIN	   := Test
MYMAINCXX  := $(MYMAIN).cxx
MYMAINO	   := $(MYMAIN).o

#All header files and source files are expected in the current directory

#The first target defined is the default for the makefile
CXX	= /usr/bin/g++
RM	= /bin/rm -f
SHELL   = /bin/sh
MAKE    = /usr/bin/make

#A useful shortcut to the current makefile location
where-am-i=$(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))
THISMAKEFILE := $(call where-am-i)

##### Library path and compiler / linker / rootcint options #####

LPATH		= lib
CXXFLAGS	= -O0 -Wall -fPIC
CXX		= g++
SOFLAGS		= -O0 -shared

#If you want to compile in Debug mode
#Add information for gdb (the debugger) and do not optimize
DEBUGFLAGS      = -g -O0
ROOTCINT	= rootcint

##### Libraries to pull in and flags #####

#for the dependency generation, it is often useful to add the last two directories 
#to supress warnings (and get the dependencies correct)
ROOTCFLAGS   	:= $(shell root-config --cflags) 
#-I${ROOTSYS}/cint/cint/include -I${ROOTSYS}/cint/cint/include/stl
ROOTLIBS     	:= $(shell root-config --libs)
ROOTGLIBS    	:= $(shell root-config --glibs)

CXXFLAGS	+= $(ROOTCFLAGS) -I./
SOFLAGS 	+= $(ROOTGLIBS) -L./

#Add specific options for our EXE to enable it to find shared libraries
EXEFLAGS        = $(CXXFLAGS) -L./ $(ROOTGLIBS)

#If mode variable is debug, compile in debug mode
#to set the mode, type 'make mode=debug'
ifeq ($(mode),debug)
CXXFLAGS+=$(DEBUGFLAGS)
endif

##### All our targets#####

# CPPFILE    := $(shell cd $(SRCSUBDIR); ls *.cpp; cd ..)
# CPPFILEDIR := $(wildcard $(SRCSUBDIR)/*.cpp)
CPPFILES   := Tensor.cxx TensorDim1.cxx TensorDim2.cxx TensorDim3.cxx TensorDim4.cxx TensorUtils.cxx
#ALLLIBS	   := $(patsubst %.cxx, lib%.so, $(CPPFILE))
#ALLLIBSDIR := $(foreach FILE, $(ALLLIBS), $(FILE))
#ALLEXES    := $(MYMAIN)# $(PLOTNUE)
#ALLEXESDIR := $(BINSUBDIR)/$(MYMAIN)

ALLLIBS    := libTensor.so libTensorDim1.so libTensorDim2.so libTensorDim3.so libTensorDim4.so libTensorUtils.so
#finally, you presumably want to link your executable against all of the objects you wrote files for
#EXEFLAGS += $(ALLLIBS)

##### Rules #####
.SUFFIXES: .cpp .d .P
#.SECONDARY: $(patsubst $(SRCSUBDIR)/%.cpp, $(SOSUBDIR)/%.o, $(CPPFILES)) $(MYMAINO)
#add any targets that do not produce a file with the same name as target to the .PHONY list.
#This prevents make from thinking that a target is up to date in some circumstances.
.PHONY: all clean $(SUBDIRS)
#Default target (without this line, the default target is the first dependency file to be insluded)
default: all

###Generic rules####

#Compile a static object file from a source file
#Also, generate the object dependencies files  (.P files)  generically (include-file dependencies)
%.o: %.cxx
	@echo "Making : " $@
	@echo "from   : " $^
	@echo $(CXX) -MD $(CXXFLAGS) -c $^ -o ./$@
	$(CXX) -MD $(CXXFLAGS) -c $^ -o ./$@
##	cp $*.d $*.P; \
#	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
#	    -e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
#	rm -f $*.d
#-include $($(APPSUBDIR)/$(MYMAINCXX:.cxx=.d))


#Create a shared library
lib%.so: %.o
	@echo "Making : " $@
	@echo "from   : " $^
	@echo $(CXX) $(SOFLAGS) -o ./$@ ./$^
	$(CXX) $(SOFLAGS) -o ./$@ ./$^

##### Rules for specific targets #####

all: $(ALLLIBS) $(ALLEXES)
	@echo "All src  : " $(CPPFILEDIR)
	@echo "All libs : " $(ALLLIBSDIR)
	@echo "All exe  : " $(ALLEXESDIR)

clean: 
	@echo $(ALLLIBS)
	@echo $(RM) *.o *.d *.P *.so 
	$(RM) *.o *.d *.P *.so

# debug: CXXFLAGS += -DDBUG -g
# debug: $(ALLLIBS) $(MYMAIN)

$(MYMAIN): $(MYMAINO) $(ALLLIBS)
	@echo "Making : " $@
	@echo "from   : " $(SOSUBDIR)/$^
	@echo $(CXX) $(EXEFLAGS)  $(wildcard $(SOSUBDIR)/*.so) $(SOSUBDIR)/$(MYMAINO) -o $@
	$(CXX) $(EXEFLAGS) $(wildcard $(SOSUBDIR)/*.so) $(SOSUBDIR)/$(MYMAINO) -o $@

$(PLOTNUE): $(PLOTNUEO) $(ALLLIBS)
	@echo "Making : " $@
	@echo "from   : " $(SOSUBDIR)/$^
	@echo $(CXX) $(EXEFLAGS)  $(wildcard $(SOSUBDIR)/*.so) $(SOSUBDIR)/$(PLOTNUEO) -o $@
	$(CXX) $(EXEFLAGS) $(wildcard $(SOSUBDIR)/*.so) $(SOSUBDIR)/$(PLOTNUEO) -o $@
# subdirs: $(SUBDIRS)

# $(SUBDIRS):
# 	$(MAKE) -C $@