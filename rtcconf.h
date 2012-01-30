#ifndef RTC_CONF_HEADER_INCLUDED
#define RTC_CONF_HEADER_INCLUDED


#ifdef USE_ETHERNET_CONNECTION

#define IPaddr(a1, a2, a3, a4) \
  ((((uint32_t)a4) << 24) | (((uint32_t)a3) << 16) | (((uint32_t)a2) << 8) | (((uint32_t)a1) << 0))

#define MACaddr(a1, a2, a3, a4, a5, a6) \
  ((((uint64_t)a6) << 40) | (((uint64_t)a5) << 32) | (((uint64_t)a4) << 24) | (((uint64_t)a3) << 16) | (((uint64_t)a2) << 8) | (((uint64_t)a1) << 0))

/*
uint8_t* MACaddr(uint8_t a1, uint8_t a2, uint8_t a3, uint8_t a4, uint8_t a5, uint8_t a6) {
  uint8_t* ret = (uint8_t*)malloc(sizeof(uint8_t)*6);
  ret[0] = a1, ret[1] = a2, ret[2] = a3, ret[3] = a4, ret[4] = a5, ret[5] = a6;
  return ret;
}
*/
#endif



struct default_str {
  //#ifdef USE_ETHERNET_CONNECTION
  uint64_t mac_address;
  uint16_t port;
  uint32_t default_gateway;
  uint32_t ip_address;
  uint32_t subnet_mask;
  //#endif

  //#ifdef USE_UART_CONNECTION
  uint16_t baudrate;
  //#endif
  
  uint8_t connection_type;
};


struct ether_str {
};

struct config_str {
  struct default_str _default;
};

struct exec_cxt_str {
  struct periodic_str {
    //#ifdef USE_TIMER1_EC
    float rate;
    //#endif
    uint8_t type;
  }periodic;
};

#ifdef USE_UART_CONNECTION
#define ConnectionTypeSerial1 0x01
#define ConnectionTypeSerial2 0x02
#define ConnectionTypeSerial3 0x03
#endif

#ifdef USE_ETHERNET_CONNECTION
#define ConnectionTypeEtherTcp 0x04
#endif

#define ProxySynchronousExecutionContext 0x21

#ifdef USE_TIMER1_EC
#define Timer1ExecutionContext 0x22
#endif

#define Timer2ExecutionContext 0x23

#endif
