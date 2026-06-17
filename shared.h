
#pragma once

// message queue attributes
#include <mqueue.h>
#define MQ_ATTR_DEFAULT                                                        \
  (struct mq_attr) {                                                           \
    .mq_msgsize = 4, .mq_maxmsg = 8, .mq_curmsgs = 2, .mq_flags = O_NONBLOCK   \
  }

// message queue name
#define QUEUE_NAME "/testq1"
