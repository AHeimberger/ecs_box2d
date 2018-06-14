#ifndef EVENTS_H
#define EVENTS_H

struct ChangeBox2dDebugOutput
{
    ChangeBox2dDebugOutput(bool showBox2dDebug) : showBox2dDebug(showBox2dDebug) {}

    bool showBox2dDebug;
};

#endif