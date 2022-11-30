#include  <iostream>
#include <string>
#include "Medicine.h"
#include "vector"
#include <algorithm>

using namespace std;

class Pharmacy {
private:
    vector<Medicine> medicines;
public:
    Pharmacy() = default;

    Medicine& GetCheapestMedicine(){
        auto a = std::min(medicines.begin(), medicines.end(),
                 [](auto a, auto b) { return a->GetDiscountPrice() < b->GetDiscountPrice(); });
        return *a;

        int cheapestMedicine = 0;
        for(int i = 0; i < medicines.size(); i++){
            int currentMedicinePrice = medicines[i].GetDiscountPrice();
            if (currentMedicinePrice < medicines[cheapestMedicine].GetDiscountPrice()){
                cheapestMedicine = i;
            }
        }
        return medicines[cheapestMedicine];
    }

    void AddMedicine(Medicine medicine){
        medicines.push_back(medicine);
    }

    void DeleteMedicine(int index) {
        medicines.erase(medicines.begin()+index);
    }

    void DeleteExpired(int currYear, int currMonth, int currDay){
        std::remove_if(medicines.begin(), medicines.end(),

                       [&currDay, &currMonth, &currYear](auto a) { return a.CheckIfExpired(currYear,currMonth,currDay);} );
    }
};
