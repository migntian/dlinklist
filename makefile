.PHONY:clean
main:dlinklist.c
	gcc  $^ -o  $@
clean:
	rm main
