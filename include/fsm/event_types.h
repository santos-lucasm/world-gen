#ifndef __EVENT_TYPES_H__
#define __EVENT_TYPES_H__

enum class Event
{
    NONE,

    // entry windows events
    START_MAINWINDOW_EXEC,

    // main window events
    PAUSE_PROCEDURAL_GENERATION,
    RESUME_PROCEDURAL_GENERATION
};

#endif