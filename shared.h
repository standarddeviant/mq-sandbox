
#pragma once

#include <stdint.h>

// message queue attributes
#include <mqueue.h>
#define MQ_ATTR_DEFAULT                                                        \
  (struct mq_attr) {                                                           \
    .mq_msgsize = 4, .mq_maxmsg = 8, .mq_curmsgs = 2, .mq_flags = O_NONBLOCK   \
  }

// message queue name
#define QUEUE_NAME "/testq1"

// function declarations for open, send_u32, recv_u32
mqd_t shared_queue_open(void);
mqd_t shared_queue_destroy(void);
int shared_queue_send_u32(mqd_t mq, uint32_t value);
ssize_t shared_queue_recv_u32(mqd_t mq, uint32_t *p_value);
