obj-m += process_test_dfs.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

run:
	sudo insmod process_test_dfs.ko
	sudo rmmod process_test_dfs
	dmesg -c