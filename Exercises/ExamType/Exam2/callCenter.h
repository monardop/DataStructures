#ifndef CALLCENTER_H
#define CALLCENTER_H

    #include "utilities.h"
    #include "listInterface.h"

    int loadOperators(dsList *activeOperators);
    int assignCall(dsList *freeWorkers);
    int endCall(dsList *onCallWorkers);
    void showOperators(dsList *activeOperators);
    void ceaseAttention(dsList *activeOperators);

#endif