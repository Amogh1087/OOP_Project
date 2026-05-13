#pragma once
#include "Pathfinder.h"
#include <vector>

namespace DroneSim {

    enum class AIState {
        IDLE,
        TRACKING_TARGET,
        SEEKING_FUEL,
        EVADING_OBSTACLE
    };

    class AILogicController {
    private:
        const IEnvironment* env;
        const IDroneState* droneState;
        Pathfinder pathfinder;
        
        AIState currentState;
        std::vector<Point> currentPath;
        Point lastKnownTarget;

        const float CRITICAL_FUEL_THRESHOLD = 20.0f; // Percentage

        // Private logic handlers declared here
        void evaluateState(Point currentPos, Point currentTarget);
        Point handleRefueling(Point currentPos);
        Point handleTracking(Point currentPos, Point currentTarget);
        Point extractNextStep(Point currentPos);

    public:
        // Constructor and main update function declared here
        AILogicController(const IEnvironment* e, const IDroneState* d);
        Point determineNextMove(Point currentTarget);
    };

}