

#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "shared.h"

int main() {
  mqd_t mq;

  uint32_t answer = 42;
  struct mq_attr mq_attr = MQ_ATTR_DEFAULT;

  // Open or create the queue with read/write access
  mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY | O_NONBLOCK, 0666, &mq_attr);
  if (mq == (mqd_t)-1) {
    perror("Sender: mq_open failed");
    printf("mq = %d, err = %s\n", mq, strerror(errno));
    exit(1);
  }

  // Send the message (0 indicates the message priority)
  if (mq_send(mq, (const char *)&answer, sizeof(answer), 0) == -1) {
    perror("Sender: mq_send failed");
    exit(1);
  }

  printf("Sender: Message successfully sent to the queue.\n");

  // Close the descriptor resource
  mq_close(mq);
  return 0;
}
