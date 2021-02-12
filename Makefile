all: clean build
build:
	g++ k-means.cpp -o k-means
clean:
	rm -f k-means
run:
	./k-means
