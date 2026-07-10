#include "ethernet.h"
#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>
struct ethernet_header {
  uint8_t dest_mac[6];
  int8_t src_mac[6];
  uint16_t ethertype;
} __attribute__((packed));

void parse_ethernet_frame(const uint8_t *frame, int len) {
  struct ethernet_header *hdr = (struct ethernet_header *)frame;

  uint16_t type = ntohs(hdr->ethertype);
  printf("Dest MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", hdr->dest_mac[0],
         hdr->dest_mac[1], hdr->dest_mac[2], hdr->dest_mac[3], hdr->dest_mac[4],
         hdr->dest_mac[5]);

  printf("Dest MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", hdr->src_mac[0],
         hdr->src_mac[1], hdr->src_mac[2], hdr->src_mac[3], hdr->src_mac[4],
         hdr->src_mac[5]);
  printf("EtherType: 0x%04x\n", type);
}
