#include "AirlineTicket.h"

AirlineTicket:: AirlineTicket()
{
	m_passName = "Unknown";
	m_numofMiles = 0;
	m_plat = false;
}

AirlineTicket:: ~AirlineTicket(){}

double AirlineTicket::calculatePrice()
{
	if (hasplat()) {
		return 0;
	}
	return getNumberofmiles() * 10;
}


std::string AirlineTicket::getPassengerName() { return m_passName; }
void AirlineTicket::setPassengerName(std::string name) { m_passName = name; }

int AirlineTicket::getNumberofmiles() { return m_numofMiles; }
void AirlineTicket::setNumberofmiles(int miles) { m_numofMiles = miles; }

bool AirlineTicket::hasplat() { return m_plat; }
void AirlineTicket::setplat(bool stat) { m_plat = stat; }
