cmd_/home/vagrant/shared/hello.ko := ld -r -m elf_x86_64 -T /usr/src/linux-headers-3.13.0-83-generic/scripts/module-common.lds --build-id  -o /home/vagrant/shared/hello.ko /home/vagrant/shared/hello.o /home/vagrant/shared/hello.mod.o