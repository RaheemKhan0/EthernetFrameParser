# EthernetFrameParser

A lightweight Ethernet frame parser written in C that reads raw Layer 2 frames from a Linux TAP virtual network interface and parses their headers.

## What it does

- Opens a TAP device (`/dev/net/tun`) to create a virtual network interface
- Reads raw Ethernet frames one at a time from the interface
- Parses the 14-byte Ethernet header from each frame:
  - **Destination MAC address** (6 bytes)
  - **Source MAC address** (6 bytes)
  - **EtherType** (2 bytes) — identifies the protocol (IPv4, IPv6, ARP, etc.)
- Prints the parsed header fields to the terminal in real time

## Building

```bash
make
```

## Running

The program requires root privileges to create a TAP device:

```bash
sudo ./ethparser
```

In a separate terminal, bring the interface up and generate traffic:

```bash
sudo ip link set tap0 up
sudo ip addr add 192.168.1.1/24 dev tap0
ping 192.168.1.2
```

## Project Structure

```
main.c        - Entry point, read loop
tap.h / tap.c - TAP device open, read, write, close
ethernet.h    - Ethernet header struct definition
ethernet.c    - Frame parsing logic
Makefile      - Build rules
```

## EtherTypes

| Code     | Protocol |
|----------|----------|
| `0x0800` | IPv4     |
| `0x0806` | ARP      |
| `0x86dd` | IPv6     |
