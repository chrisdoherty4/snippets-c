all: converter

clean:
	rm cel2far far2cel

converter: converter.c
	rm -f ./far2cel
	cc -o cel2far converter.c
	ln -s cel2far far2cel
