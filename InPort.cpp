/*******************************************
 * InPort.cpp
 * @author Yuki Suga
 * @copyright Yuki Suga (ysuga.net) Nov, 10th, 2010.
 * @license LGPLv3
 *****************************************/


#include <string.h>
#include "Packet.h"
#include "ReceivePacket.h"
#include "SendPacket.h"
#include "BasicDataType.h"
#include "InPort.h"


InPort::InPort(char* name, TimedDouble& Data):
  InPortBase(name)
{
  m_pData = &Data;
  m_TypeCode = 'd';
}

InPort::InPort(char* name, TimedFloat& Data):
  InPortBase(name)
{
  m_pData = &Data;
  m_TypeCode = 'f';
}

InPort::InPort(char* name, TimedLong& Data):
  InPortBase(name)
{
  m_pData = &Data;
  m_TypeCode = 'l';
}

InPort::InPort(char* name, TimedDoubleSeq& Data):
  InPortBase(name)
{
  m_pData = &Data;
  m_TypeCode = 'D';
}

InPort::InPort(char* name, TimedFloatSeq& Data):
  InPortBase(name)
{
  m_pData = &Data;
  m_TypeCode = 'F';
}

InPort::InPort(char* name, TimedLongSeq&Data):
  InPortBase(name)
{
  m_pData = &Data;
  m_TypeCode = 'L';
}

InPort::~InPort()
{
}


int InPort::isNew()
{
  char packet_buffer[MAX_PACKET_SIZE];
  SendPacket(INPORT_ISNEW, strlen(GetName()), GetName());
  ReceivePacket(packet_buffer);
  if(packet_buffer[INTERFACE] != INPORT_ISNEW) {
    return 0;//-INVALID_PACKET_INTERFACE;
  }
  return packet_buffer[DATA_START_ADDR];
}


int InPort::read() {
  char packet_buffer[MAX_PACKET_SIZE];
  SendPacket(INPORT_READ, strlen(GetName()), GetName());
  ReceivePacket(packet_buffer);
  if(packet_buffer[INTERFACE] != INPORT_READ) {
    return -INVALID_PACKET_INTERFACE;
  }
  int len = packet_buffer[DATA_LENGTH] / SizeofData();
  int isSequence = isSequenceType();
  SetLength(len);
  void *pBuffer = GetBuffer();
  memcpy(pBuffer, &(packet_buffer[DATA_START_ADDR]), len*SizeofData());
  return len;
}
