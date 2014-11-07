//这个目录下存放学习《Unix环境高级编程》一书所产生的文件

编译该目录下源程序前，需要做以下工作：
将SourceCodeOfBook_part文件夹下的apue.h文件拷贝到/usr/include目录下，
sudo chmod a+r /usr/include/apue.h
vi ~/.bashrc
	//在其末尾添加下面这行，.......处指的是存放error.c的目录
	apue_error=/home/......../error.c
source ~/.bashrc
gcc codelistxxx.c ${apue_error} -o xxx

参考资料：http://www.cnblogs.com/yhLinux/
