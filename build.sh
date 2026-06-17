gcc shared.c sender.c -o send -lrt
gcc shared.c receiver.c -o recv -lrt
gcc shared.c unlink.c -o unlink -lrt
