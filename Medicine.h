
//kkk
#include <string>
#include <chrono>
using namespace std;

class Medicine {
private:
    int expirationYear;
    int expirationMonth;
    int expirationDay;
    //std::chrono::time_point<std::chrono::system_clock> expDate;
    int quantity;
    int price;

public:
    string name;
    Medicine() = default;


    Medicine(string name, int price){
        this->name = name;
        this->price = price;

    }

    bool CheckIfExpired(int currYear, int currMonth, int currDay){
        if(expirationYear < currYear)
            return true;
        if (expirationMonth < currMonth)
            return true;
        if (expirationDay < currDay)
            return true;

        return false;
    }

    int GetDiscountPrice() {
        return price * 0.9;
    }

};