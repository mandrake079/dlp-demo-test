/* SYNTHETIC TEST FILE - NOT REAL CODE. For DLP testing only.
 * Proprietary C - line card packet parser (fictional) */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "otn_frame.h"

#define OTN_HDR_LEN 16

static int parse_header(const uint8_t *buf, size_t len, otn_hdr_t *out) {
    if (len < OTN_HDR_LEN) return -1;
    out->fas      = (buf[0] << 8) | buf[1];
    out->mfas     = buf[2];
    out->odu_type = buf[3] & 0x0F;
    memcpy(out->payload_id, &buf[4], 4);
    return 0;
}

int main(int argc, char **argv) {
    uint8_t frame[64] = {0xF6, 0x28, 0x01, 0x02};
    otn_hdr_t h;
    if (parse_header(frame, sizeof(frame), &h) == 0)
        printf("ODU type %u, MFAS %u\n", h.odu_type, h.mfas);
    return 0;
}
