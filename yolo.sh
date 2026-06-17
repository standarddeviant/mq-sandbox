git clone https://github.com/standarddeviant/mq-sandbox.git
cd mq-sandbox
./build.sh
./receiver &
sleep 2
./sender
