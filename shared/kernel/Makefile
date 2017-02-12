#############################
## Makefile - Jacob Adkins ##
#############################

#CXX = gcc
#CXXFLAGS = -Wall

#all : userspace kernelspace

#a.out : userspace.c
#	${CXX} $^ ${CXXFLAGS} -o $@

#a.out : kernelspace.c
#	${CXX} $^ ${CXXFLAGS} -o $@

#clean :
#	\rm -f userspace kernelspace

###### End of Makefile ###### 

obj-m += test_module.o

all:
	    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
