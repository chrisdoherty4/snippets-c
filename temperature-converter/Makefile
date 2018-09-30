all: converter

clean:
	rm cel2far far2cel

converter: clean
	cc -o cel2far converter.c
	ln -s cel2far far2cel
