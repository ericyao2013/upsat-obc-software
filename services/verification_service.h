#ifndef __VERIFICATION_SERVICE_H
#define __VERIFICATION_SERVICE_H

#include <stdint.h>
#include "services.h"

//ToDo
//  check verify_pkt

extern void *get_pkt(uint8_t mode);
extern uint32_t time_now();
extern SAT_returnState crt_pkt(tc_tm_pkt *pkt, uint16_t app_id, uint8_t type, uint8_t ack, uint8_t ser_type, uint8_t ser_subtype, uint16_t dest_id);
extern SAT_returnState route_pkt(tc_tm_pkt *pkt);

SAT_returnState verification_app(tc_tm_pkt *pkt, SAT_returnState res); 

SAT_returnState verification_crt_pkt(tc_tm_pkt *pkt, tc_tm_pkt *out, SAT_returnState res);

#endif
