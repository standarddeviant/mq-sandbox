
# mq-sandbox
This is a basic example of using message queues for IPC on Linux.

# YOLO Instructions

```
git clone https://github.com/standarddeviant/mq-sandbox.git
cd mq-sandbox
./build.sh

# start recv
./recv &
sleep 2

# start send
./send
sleep 1

# unlink (i.e. destroy) the shared queue
echo ">>> Before unlink:"
ls /dev/mqueue/

./unlink

echo ">>> After unlink:"
ls /dev/mqueue/
```
