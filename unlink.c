

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/stat.h>
#include <unistd.h>

#include "shared.h"

int main() {
  int rc = mq_unlink(QUEUE_NAME);
  return 0;
}
