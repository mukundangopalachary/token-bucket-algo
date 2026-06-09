# Token Bucket Algorithm Simulator in C

## Overview

This project is a simulation of the **Token Bucket Algorithm**, a widely used traffic shaping and rate-limiting mechanism in computer networks.

The simulator models packet generation, queuing, token consumption, and packet transmission while collecting statistics about accepted and dropped traffic. It can also be used to simulate high-volume traffic scenarios such as **DDoS attacks** and observe how a token bucket limits network usage.

---

## What is the Token Bucket Algorithm?

The Token Bucket Algorithm is used to control the amount of data that can be transmitted over a network.

### Basic Idea

- Tokens are generated at a fixed rate.
- Tokens are stored in a bucket.
- The bucket has a maximum capacity.
- A packet can only be transmitted if enough tokens are available.
- If sufficient tokens are not available, the packet is delayed or dropped.

### In This Simulator

```text
1 Token = 1 Byte
```

Therefore:

```text
Packet Size = Tokens Required
```

Example:

| Packet Size | Tokens Consumed |
| ----------- | --------------- |
| 64 Bytes    | 64 Tokens       |
| 512 Bytes   | 512 Tokens      |
| 1500 Bytes  | 1500 Tokens     |

---

## Features

- Cross-platform timer abstraction
- Token bucket implementation
- Packet generation and validation
- Linked-list based packet queue
- Traffic generation modes
- Statistics collection
- DDoS traffic simulation
- Queue overflow handling
- Token bucket drop tracking

---

## Project Structure

```text
token_bucket_algorithm/
│
├── include/
│   ├── packet.h
│   ├── queue.h
│   ├── stats.h
│   ├── timer.h
│   ├── token_bucket.h
│   └── traffic_generator.h
│
├── src/
│   ├── main.c
│   ├── packet.c
│   ├── queue.c
│   ├── stats.c
│   ├── timer.c
│   ├── token_bucket.c
│   └── traffic_generator.c
│
├── build/
│
├── Makefile
│
└── README.md
```

---

## Architecture

```text
Traffic Generator
        │
        ▼
      Packet
        │
        ▼
       Queue
        │
        ▼
   Token Bucket
        │
 ┌──────┴──────┐
 │             │
 ▼             ▼
Transmit      Drop
 │             │
 └──────┬──────┘
        ▼
   Statistics
```

---

## Module Description

### Timer Module

Responsible for obtaining monotonic timestamps.

Functions:

```c
uint64_t currentMillis();
```

Used by:

- Packet timestamps
- Token bucket refill calculations

---

### Packet Module

Represents packets entering the network.

Packet Structure:

```c
typedef struct {
    uint32_t id;
    uint32_t source_id;
    size_t size;
    uint64_t arrival_time;
} Packet;
```

Features:

- Automatic packet ID generation
- Packet size validation
- Arrival timestamp recording

Valid packet size range:

```text
64 bytes - 1500 bytes
```

---

### Queue Module

Linked-list based FIFO queue.

Responsibilities:

- Store incoming packets
- Preserve packet order
- Handle queue overflow

Operations:

```c
enqueue()
dequeue()
peek()
isEmpty()
isFull()
```

---

### Token Bucket Module

Core rate-limiting component.

Token Bucket Structure:

```c
typedef struct {
    double capacity;
    double tokens;
    uint64_t last_refill;
    double fill_rate;
} TokenBucket;
```

Responsibilities:

- Token generation
- Bucket refill
- Token consumption
- Packet admission control

Refill Formula:

```text
tokens_added =
(fill_rate / 1000) × elapsed_time_ms
```

---

### Traffic Generator Module

Generates simulated network traffic.

Traffic Modes:

#### Normal Traffic

```text
Single source
Steady traffic
```

#### Burst Traffic

```text
Multiple sources
Short traffic spikes
```

#### DDoS Traffic

```text
Large number of attacking sources
High packet generation rate
```

---

### Statistics Module

Collects performance metrics.

Tracked Metrics:

```text
Packets Generated
Packets Queued
Packets Transmitted
Packets Dropped

Bytes Generated
Bytes Transmitted
Bytes Dropped

Queue Overflow Drops
Token Bucket Drops
```

---

## Simulation Flow

### Step 1

Generate a packet.

```text
Traffic Generator
        │
        ▼
      Packet
```

### Step 2

Validate packet size.

```text
64 ≤ size ≤ 1500
```

### Step 3

Add packet to queue.

```text
Packet
  │
  ▼
Queue
```

### Step 4

Refill token bucket based on elapsed time.

```text
New Tokens =
(fill_rate × elapsed_time_ms) / 1000
```

### Step 5

Check token availability.

```text
tokens >= packet_size ?
```

### Step 6

Transmit or drop packet.

```text
Enough Tokens
      │
      ▼
  Transmit

Not Enough Tokens
      │
      ▼
     Drop
```

### Step 7

Update statistics.

---

## DDoS Simulation

The simulator can emulate DDoS-like traffic conditions.

Characteristics:

```text
Large number of sources
High packet generation rate
Variable packet sizes
Queue saturation
Token exhaustion
```

This allows observation of:

- Queue overflow behavior
- Rate limiting effectiveness
- Packet drop rates
- Bandwidth consumption

---

## Building the Project

```bash
make
```

---

## Running the Simulator

```bash
make run
```

---

## Cleaning Build Files

```bash
make clean
```

---

## Example Output
[token_bucket_image](./token_bucket_op.png)
---

## Future Improvements

- Multi-threaded traffic generation
- Multiple token buckets
- Priority queues
- Leaky Bucket comparison
- Real packet arrival distributions
- Attack pattern profiles
- Throughput and latency analysis
- Configuration through files
- Visualization dashboard

---

## Concepts Demonstrated

- Token Bucket Algorithm
- Traffic Shaping
- Rate Limiting
- Queue Management
- DDoS Mitigation
- Linked Lists
- Modular C Programming
- Network Traffic Simulation
- Statistics Collection
- Cross-Platform Development

```

```
