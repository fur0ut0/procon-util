STD ?= 2a

CXX ?= g++
CXXFLAGS := -fdiagnostics-color=always -std=c++$(STD) -I. -Wall -Wextra

.PHONY: clean debug release

release: CXXFLAGS += -O2
debug: CXXFLAGS += -g -O0 -fsanitize=undefined,address

release: a.out
debug: a.debug.out
clean:
	@read -p "Are you sure to clear all changes? (y/N): " p \
		&& test $$p = y -o $$p = Y
	$(RM) -rf test a.out a.debug.out
	git checkout -- main.cpp

a.out: main.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)

a.debug.out: main.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)
