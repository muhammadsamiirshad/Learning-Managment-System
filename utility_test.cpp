#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include "utility.h"

using namespace std;

int main() {
    // Test UserInterface class
    UserInterface::displayLogo();
    
    const string menuOptions[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit"
    };
    const int menuOptionCount = 4;
    
    int choice = UserInterface::displayMenu("TEST MENU", menuOptions, menuOptionCount);
    
    UserInterface::showSuccess("Test completed successfully! Your choice was: " + to_string(choice));
    
    return 0;
}