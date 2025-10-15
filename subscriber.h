#pragma once
class Subscriber
{ 
    public:
        virtual void notify(int state) = 0;
};