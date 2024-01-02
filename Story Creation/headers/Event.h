#pragma once
#include <vector>
#include "Character.h"
#include "Logger.h"

struct Event{
public:
    std::string name;
    bool is_Triggered;

    Event(std::string _name, bool _is_Triggered) : name(_name), is_Triggered(_is_Triggered)
    {
        
    }

    ~Event(){

    }

    void AddLink(Event event)
    {
        events.push_back(event);
    }

    std::vector<Event> GetLinkedEvents(){
        return events;
    }

private:
    std::vector<Event> events;
};

class EventSystem
{
public:
    EventSystem(std::string event_system_name) : currEvent("", false), logger(event_system_name)
    {

    }

    ~EventSystem()
    {
    }

    void AddEvent(std::string name)
    {
        events.push_back(Event{name, false});
    }

    void AddEvent(Event ev)
    {
        events.push_back(ev);
    }

    void TriggerLinkedEvent(std::string event_name)
    {
        for (int i = 0; i < events.size(); i++) {
            for (int j = 0; j < events[i].GetLinkedEvents().size(); j++) 
            {
                if (events[i].GetLinkedEvents()[j].name == event_name)
                {
                    events[i].is_Triggered = false;
                    events[i].GetLinkedEvents()[j].is_Triggered = true;
                }
            }
            
        }
    }

    void ActivateLinkEvents()
    {
        for(int i = 0; i < events.size(); i++)
        {
            for(int j = 0; j < events[i].GetLinkedEvents().size(); j++){
                if(events[i].is_Triggered)
                {
                    if(!events[i].GetLinkedEvents()[j].is_Triggered)
                    {
                        logger.Log("Event " + events[i].GetLinkedEvents()[j].name + " has not been triggered.");
                    }
                    if(events[i].GetLinkedEvents()[j].is_Triggered)
                    {
                        currEvent = events[i].GetLinkedEvents()[j];
                        logger.Log("Event " + currEvent.name + " is the current event");
                    }
                    if(events[i].is_Triggered)
                    {
                        currEvent = events[i];
                        logger.Log("Event " + currEvent.name + " is the current event");
                    }
                }
            }
        }
    }

    Event GetCurrentEvent() {
        return currEvent;
    }

private:
    std::vector<std::string> characters;
    std::vector<Event> events;

    Event currEvent;

    Logger logger;
};