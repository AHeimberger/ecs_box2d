#ifndef CONTROL_H
#define CONTROL_H

struct Control
{
    Control(double upthrust, double sidethrust)
        : upthrust(upthrust), sidethrust(sidethrust) {}

    double upthrust;
    double sidethrust;
};

#endif