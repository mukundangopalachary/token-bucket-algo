#include "../include/queue.h"

#include <stdlib.h>

void initQueue(PacketQueue *queue, size_t max_size) {
  queue->front = NULL;
  queue->rear = NULL;
  queue->size = 0;
  queue->max_size = max_size;
}

bool enqueue(PacketQueue *queue, Packet packet) {
  if (isFull(queue))
    return false;

  QueueNode *node = malloc(sizeof(QueueNode));

  if (node == NULL)
    return false;

  node->packet = packet;
  node->next = NULL;

  if (queue->rear == NULL) {
    queue->front = node;
    queue->rear = node;
  } else {
    queue->rear->next = node;
    queue->rear = node;
  }

  queue->size++;

  return true;
}

bool dequeue(PacketQueue *queue, Packet *packet) {
  if (isEmpty(queue))
    return false;

  QueueNode *temp = queue->front;

  *packet = temp->packet;

  queue->front = queue->front->next;

  if (queue->front == NULL)
    queue->rear = NULL;

  free(temp);

  queue->size--;

  return true;
}

bool peek(PacketQueue *queue, Packet *packet) {
  if (isEmpty(queue))
    return false;

  *packet = queue->front->packet;

  return true;
}

bool isEmpty(PacketQueue *queue) { return queue->size == 0; }

bool isFull(PacketQueue *queue) { return queue->size >= queue->max_size; }

size_t getQueueSize(PacketQueue *queue) { return queue->size; }

void destroyQueue(PacketQueue *queue) {
  Packet temp;

  while (dequeue(queue, &temp))
    ;

  queue->front = NULL;
  queue->rear = NULL;
  queue->size = 0;
}
