#ifndef ROUTE_VERIFICATION_H
#define ROUTE_VERIFICATION_H

#include <stdint.h>
#include "tc_tm.h"

//temp
#define TEST_ARRAY 1024

extern void *get_pkt(uint8_t mode);
extern OBC_returnStateTypedef free_pkt(tc_tm_pkt *pkt);
extern uint32_t time_now();

extern OBC_returnStateTypedef verification_app(tc_tm_pkt *pkt, OBC_returnStateTypedef res); 
extern OBC_returnStateTypedef hk_app(tc_tm_pkt *pkt);
extern OBC_returnStateTypedef function_management_app(tc_tm_pkt *pkt);
extern OBC_returnStateTypedef mass_storage_app(tc_tm_pkt *pkt);
extern OBC_returnStateTypedef large_data_app(tc_tm_pkt *pkt);
extern OBC_returnStateTypedef test_app(tc_tm_pkt *pkt);

extern OBC_returnStateTypedef unpack_pkt(const uint8_t *buf, tc_tm_pkt *pkt, const uint16_t size);
extern OBC_returnStateTypedef pack_pkt(uint8_t *buf, tc_tm_pkt *pkt, uint16_t *size);

extern OBC_returnStateTypedef HLDLC_deframe(uint8_t *buf, uint16_t *cnt, const uint8_t c);
extern OBC_returnStateTypedef HLDLC_frame(uint8_t *c, uint8_t *buf, uint16_t * cnt, const uint16_t size);

extern void HAL_eps_uart_tx(uint8_t *buf, uint16_t size);
extern OBC_returnStateTypedef HAL_eps_uart_rx(uint8_t *c);

//ToDo
//  Add if condition for normal packet or extended

OBC_returnStateTypedef route_pkt(tc_tm_pkt *pkt);

OBC_returnStateTypedef import_eps_pkt();

OBC_returnStateTypedef export_eps_pkt(tc_tm_pkt *pkt);

#endif
