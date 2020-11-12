obj-m += my_module.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:	
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

load:
	sudo insmod my_module.ko
	sudo dmesg -c

unload:
	sudo rmmod my_module.ko
	sudo dmesg -c

test:
	sudo dmesg -C
	sudo insmod my_module.ko
	sudo rmmod my_module.ko
	dmesg