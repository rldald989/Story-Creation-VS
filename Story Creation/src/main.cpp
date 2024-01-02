#include <iostream>
#include "../headers/Event.h"

void Print(std::string input){
    std::cout << input << std::endl;
}

void Print(int input){
    std::cout << input << std::endl;
}

void Print(iVec2 input){
    std::cout << "x: " << input.x << 
    ", y: " << input.y << std::endl;
}

int main()
{
    std::string input;

    EventSystem event_system("Ev_Sys");

    Event event_1("School Room", true);
    Event event_2("Hall", false);

    event_1.AddLink(event_2);

    event_system.AddEvent(event_1);

    while (std::cin >> input)
    {
        if (input == "active")
        {
            event_system.TriggerLinkedEvent("Hall");
            std::cout << event_system.GetCurrentEvent().is_Triggered << std::endl;
        }
        
        event_system.ActivateLinkEvents();
    }
    
}