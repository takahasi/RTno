#ifndef TRANSPORT_HEADER_INCLUDED
#define TRANSPORT_HEADER_INCLUDED

#include <stdint.h>
#include "SerialDevice.h"

int8_t Transport_init();

int8_t Transport_SendPacket(const char interface, const uint8_t data_length, const int8_t* packet_data);
	
int8_t Transport_ReceivePacket(int8_t* packet);

#endif
