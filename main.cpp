#include "SystemController.h"
using namespace std;
int main() {
	SystemController car;
	car.Start();
	car.WriteDataToStorage();
	return 0;
}