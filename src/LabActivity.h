#include <stddef.h>
#include <stdbool.h>

typedef struct LabViewDimensions {
    float w, h;             // view full width and height
    float wx, wy, ww, wh;   // window within the view
} LabViewDimensions;

typedef struct LabViewInteraction {
    LabViewDimensions view;
    float x = 0, y = 0, dt = 0;
    bool start = false, end = false;  // start and end of a drag
} LabViewInteraction;

// Define ModeActivities in a C-compatible way
typedef struct LabActivity {
    void (*Activate)(void*) = nullptr;
    void (*Deactivate)(void*) = nullptr;
    void (*Update)(void*) = nullptr;
    void (*Render)(void*, const LabViewInteraction*) = nullptr;
    void (*RunUI)(void*, const LabViewInteraction*) = nullptr;
    void (*Menu)(void*) = nullptr;
    void (*ToolBar)(void*) = nullptr;
    int  (*ViewportHoverBid)(void*, const LabViewInteraction*) = nullptr;
    void (*ViewportHovering)(void*, const LabViewInteraction*) = nullptr;
    int  (*ViewportDragBid)(void*, const LabViewInteraction*) = nullptr;
    void (*ViewportDragging)(void*, const LabViewInteraction*) = nullptr;
    const char* name = nullptr; // string is not owned by the activity
    bool active = false;
} LabActivity;
