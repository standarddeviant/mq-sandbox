gcc shared.c send.c -o send -lrt
gcc shared.c recv.c -o recv -lrt
gcc shared.c unlink.c -o unlink -lrt
