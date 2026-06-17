

#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "shared.h"

int main() {
  mqd_t mq;
  unsigned int prio;
  uint32_t answer = 0;
  struct mq_attr mq_attr = MQ_ATTR_DEFAULT;

  // Open the existing message queue for reading
  // mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, NULL);
  mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY | O_NONBLOCK, 0666, &mq_attr);
  if (mq == (mqd_t)-1) {
    perror("Receiver: mq_open failed");
    printf("mq = %d, err = %s\n", mq, strerror(errno));
    exit(1);
  }

  int ix = 0;
  while (true) {
    // Retrieve the message from the queue
    // Note: Buffer size must be >= mq_msgsize attributes of the queue
    ssize_t bytes_read = mq_receive(mq, (char *)&answer, sizeof(answer), &prio);

    printf("attempt %4d, bytes_read = %4ld\n", ix, bytes_read);
    if (bytes_read == -1) {
      // perror("Receiver: mq_receive failed");
      // exit(1);
      usleep(500000);
      continue;
    }

    printf("answer = %u\n", answer);

    break;
  }

  // Close descriptor and cleanly remove the queue from the system
  mq_close(mq);
  mq_unlink(QUEUE_NAME);

  return 0;
}
