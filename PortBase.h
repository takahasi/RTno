/*******************************************
 * PortBase.h
 * @author Yuki Suga
 * @copyright Yuki Suga (ysuga.net) Nov, 10th, 2010.
 * @license LGPLv3
 *****************************************/

#ifndef PORT_BASE_HEADER_INCLUDED
#define PORT_BASE_HEADER_INCLUDED

#include "BasicDataType.h"
class PortBase {
 private:

    
 protected:
  void* m_pData;
  char* m_pName;
  char m_TypeCode;
 public:
  PortBase(char* name);
  ~PortBase();

 public:
  char* GetName() {return m_pName;}
  char GetTypeCode() {return m_TypeCode;}

  int isSequenceType() {
    char typeCode = GetTypeCode();
    if(typeCode == 'd' || typeCode == 'f' || typeCode == 'l') {
      return 0;
    } else if(typeCode == 'D' || typeCode == 'F' || typeCode == 'L') {
      return 1;
    }
  }

  int GetLength() {
    if(!isSequenceType()) {
      return 1;
    } else {
      return ((TimedDataSeq*)m_pData)->GetBuffer()->length();
    }
  }

  void SetLength(int len) {
    if(!isSequenceType()) {
      return;
    }
    SequenceDataType *seqData = ((TimedDataSeq*)m_pData)->GetBuffer();
    seqData->length(len);
  }

  void* GetBuffer() {
    void* pBuffer;
      if(!isSequenceType()) {
      //      if (len != 1) return 0;// -INVALID_PACKET_DATASIZE;
      pBuffer = ((TimedData*)m_pData)->GetBuffer();
    } else {
      SequenceDataType *seqData = ((TimedDataSeq*)m_pData)->GetBuffer();
      pBuffer = seqData->GetBuffer();
    }
    return pBuffer;
  }

};

#endif
