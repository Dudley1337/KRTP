#include "PortCreater.h"

Ship* PortCreater::createPort(PortFactory& factory)
{
	Ship* p = new Ship;
	p->Ñharacteristic = factory.createShips_characteristics();
	return p;
}