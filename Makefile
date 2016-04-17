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
DBGCFLAGS = -g -O0 -DDEBUG -Wall
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS))

#
# Unit test build
#
TESTDIR = tests
TESTSRCS := $(wildcard ${TESTDIR}/*.cpp)
PRE_TESTOBJS = $(patsubst %.cpp,%.o,$(TESTSRCS))
FINAL_TESTOBJS = $(addprefix $(DBGDIR)/, $(PRE_TESTOBJS))
TESTLIBS = -lcppunit
#
# Output files 
#
OUTPUTLIB = ${DBGDIR}/libalg.a
TESTTARGET = ${DBGDIR}/${TESTDIR}/main

HEADERDIR = headers
DEPS := $(shell find $(HEADERDIR)/ -name *.hpp)

all: $(OUTPUTLIB) $(TESTTARGET) 

$(OUTPUTLIB): $(DBGOBJS) 
		ar rcs $(OUTPUTLIB) $(DBGOBJS)

$(TESTTARGET): $(FINAL_TESTOBJS)
		$(CXX) $(DBGCFLAGS) -o $@ $^ $(OUTPUTLIB) $(TESTLIBS)

$(DBGDIR)/%.o:%.cpp $(SRCS) $(DEPS)
		@mkdir -p $(@D)
		$(CXX) $(DBGCFLAGS) -c $< -o $@  

$(DBGDIR)/tests/%.o:%.cpp  $(TESTSRCS) $(DEPS)
		@mkdir -p $(@D)
		$(CXX) $(DBGCFLAGS) -c $< -o $@ 


clean:
	rm -f $(DBGOBJS) $(OUTS) $(FINAL_TESTOBJS) $(TESTTARGET)
