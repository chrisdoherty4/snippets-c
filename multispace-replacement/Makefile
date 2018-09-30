all: space-replacement

clean:
	rm -f sr

space-replacement: clean
	cc -o sr space-replacement.c

test:
	@./sr "This is a    string  with     lots of      double or more   spaces."
