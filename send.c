

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "shared.h"

int main() {
  int rc;
  mqd_t mq;

  uint32_t answer = 42;

  // Open or create the queue with read/write access
  mq = shared_queue_open();
  assert(mq != (mqd_t)-1);

  rc = shared_queue_send_u32(mq, answer);

  if (0 == rc) {
    printf("Sender: Message successfully sent to the queue.\n");
  } else {
    printf("Sender: error: rc = %d, errno = %d = %s", rc, errno,
           strerror(errno));
  }

  // Close the descriptor resource
  mq_close(mq);
  return 0;
}
