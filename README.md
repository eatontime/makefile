# makefile
## sample_makefile
* 目标（target）：可执行文件“edi”和哪些.o文件（main.o,kbo）
* 依赖（perequisites）就是冒号后面的哪些.c文件和.h文件
* 命令包括 "cc -c main.c"、"cc -c kbd.c"...
* 所有的.o文件既是依赖，又是目标