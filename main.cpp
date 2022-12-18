#include <iostream>
#include <string>
#include "Pharmacy.h"
using namespace std;

int main() {
    Pharmacy pharmacy = Pharmacy();
    pharmacy.AddMedicine(Medicine("Our Cheap M", 3));
    pharmacy.AddMedicine(Medicine("Our M", 333));
    Medicine chepapestMedicine = pharmacy.GetCheapestMedicine();

    cout<<"Cheapest pharmacy: " << chepapestMedicine.name << endl;
    pharmacy.DeleteExpired(2022, 10, 10);

    return 0;
}