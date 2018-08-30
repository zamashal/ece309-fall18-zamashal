
# list the name of each file (without the .cpp file at the end)
EXE = example

all: $(EXE)

test: all $(addsuffix -test,$(EXE))

clean:
	rm -f $(EXE) *~ logfile.txt $(ECE)

%: %.cpp
	$(CXX) -o $@ $< -Wall -Werror -I ../include -L ../lib -lece309

%-test:
	@./$*

