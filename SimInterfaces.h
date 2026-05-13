#pragma once
#include <vector>
#include <cmath>
#include <functional>

namespace DroneSim {

    // Basic 2D Coordinate structure
    struct Point {
        int x, y;
        bool operator==(const Point& other) const { return x == other.x && y == other.y; }
        bool operator!=(const Point& other) const { return !(*this == other); }
    };

    // Interface for the Grid/Environment (Implemented by the Grid Team)
    class IEnvironment {
    public:
        virtual ~IEnvironment() = default;
        virtual bool isWalkable(int x, int y) const = 0;
        virtual bool isValid(int x, int y) const = 0;
        virtual std::vector<Point> getFuelStations() const = 0;
    };

    // Interface for Drone State (Implemented by the Mechanics Team)
    class IDroneState {
    public:
        virtual ~IDroneState() = default;
        virtual Point getPosition() const = 0;
        virtual float getFuelLevel() const = 0;
        virtual float getMaxFuel() const = 0;
        virtual float getFuelConsumptionRate() const = 0;
    };
}