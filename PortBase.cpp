/*******************************************
 * PortBase.h
 * @author Yuki Suga
 * @copyright Yuki Suga (ysuga.net) Nov, 10th, 2010.
 * @license LGPLv3
 *****************************************/

#include <stdlib.h>
#include <string.h>
#include "PortBase.h"

PortBase::PortBase(char* name)
{
  m_pName = (char*)malloc(strlen(name)+1);
  strcpy(m_pName, name);
}


PortBase::~PortBase()
{
  free(m_pName);
}
