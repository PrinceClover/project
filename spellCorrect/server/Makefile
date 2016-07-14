VPATH = src
./bin/server:test.cc 
	g++ ./src/*.cc -o ./bin/server 
.PHONY:clean
clean:
	rm ./bin/server
.PHONY:run
run:
	./bin/server
