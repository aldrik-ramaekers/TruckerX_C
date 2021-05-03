
main:
	mkdir -p "build/"
	cp -a "data/." "build/data"
	gcc -m64 -g -DMODE_DEBUG src/main.c -o build/truckerx.exe -lprojectbase-debug
	./build/truckerx.exe