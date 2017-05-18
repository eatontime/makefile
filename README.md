# makefile
## sample_makefile
* 目标（target）：可执行文件“edi”和哪些.o文件（main.o,kbo）
* 依赖（perequisites）就是冒号后面的哪些.c文件和.h文件
* 命令包括 "cc -c main.c"、"cc -c kbd.c"...
* 所有的.o文件既是依赖，又是目标
* 当规则的目标是一个文件，在它的任何一个依赖文件被修改以后，在执行“make”时这个目标文件将会被重新编译或者重新连接。