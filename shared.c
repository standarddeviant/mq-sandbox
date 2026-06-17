

#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "shared.h"

mqd_t shared_queue_open(void) {
  struct mq_attr mq_attr = MQ_ATTR_DEFAULT;
  mqd_t mq;

  // Open the existing message queue for reading
  // mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, NULL);
  mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR | O_NONBLOCK, 0666, &mq_attr);
  if (mq == (mqd_t)-1) {
    perror("mq_open failed");
    printf("mq_open failed, mq = %d, err = %s\n", mq, strerror(errno));
  }

  return mq;
}

int shared_queue_send_u32(mqd_t mq, uint32_t value) {
  // Send the message (0 indicates the message priority)
  return mq_send(mq, (const char *)&value, sizeof(value), 0);
}

ssize_t shared_queue_recv_u32(mqd_t mq, uint32_t *p_value) {
  unsigned int prio;
  return mq_receive(mq, (char *)p_value, sizeof(*p_value), &prio);
}

int shared_queue_destroy(void) { return mq_unlink(QUEUE_NAME); }
