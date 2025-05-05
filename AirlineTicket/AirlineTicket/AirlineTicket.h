#include <string>

class AirlineTicket {
public:
    AirlineTicket();
    ~AirlineTicket();

    double calculatePrice();

    int getNumberofmiles();
    void setNumberofmiles(int miles);

    std::string getPassengerName();
    void setPassengerName(std::string name);

    bool hasplat();
    void setplat(bool stat);

private:
    std::string m_passName;
    int m_numofMiles;
    bool m_plat;
};
