CXXFLAGS = -O2 -g -Wall

#
# Project source directory
#
SRCDIR = src
SRCS := $(shell find $(SRCDIR)/ -name *.cpp)
                     		
                
OBJS = $(SRCS:.cpp=.o)

#
# Debug build settings
#
DBGDIR = debug
DBGCFLAGS = -g -O0 -DDEBUG
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS))

#
# Unit test build
#
TESTDIR = tests
TESTSRCS := $(wildcard ${TESTDIR}/*.cpp)
PRE_TESTOBJS = $(patsubst %.cpp,%.o,$(TESTSRCS))
FINAL_TESTOBJS = $(addprefix $(DBGDIR)/, $(PRE_TESTOBJS))

#
# Output files 
#
OUTPUTLIB = ${DBGDIR}/libalg.a
TESTTARGET = ${DBGDIR}/${TESTDIR}/tests

COMBINE_SRCS = $(SRCS)
COMBINE_SRCS := $(TESTSRCS)

all: $(OUTPUTLIB) $(TESTTARGET) 

$(OUTPUTLIB): $(DBGOBJS) 
		ar rcs $(OUTPUTLIB) $(DBGOBJS)

$(TESTTARGET): $(FINAL_TESTOBJS)
		$(CXX) $(CXXFLAGS) -o $@ $^

$(DBGDIR)/%.o:%.cpp $(COMBINE_SRCS)
		@mkdir -p $(@D)
		$(CXX) $(CXXFLAGS) -c $< -o $@

 
		


clean:
	rm -f $(DBGOBJS) $(OUTS) $(FINAL_TESTOBJS)
