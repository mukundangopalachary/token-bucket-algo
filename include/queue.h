#ifndef QUEUE_H
#define QUEUE_H

#include "packet.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct QueueNode {
  Packet packet;
  struct QueueNode *next;
} QueueNode;

typedef struct {
  QueueNode *front;
  QueueNode *rear;
  size_t size;
  size_t max_size;
} PacketQueue;

void initQueue(PacketQueue *queue, size_t max_size);

bool enqueue(PacketQueue *queue, Packet packet);

bool dequeue(PacketQueue *queue, Packet *packet);

bool peek(PacketQueue *queue, Packet *packet);

bool isEmpty(PacketQueue *queue);

bool isFull(PacketQueue *queue);

size_t getQueueSize(PacketQueue *queue);

void destroyQueue(PacketQueue *queue);

#endif
