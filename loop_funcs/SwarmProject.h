#ifndef SWARM_PROJECT_FUNCTIONS_H
#define SWARM_PROJECT_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/core/simulator/entity/floor_entity.h>
#include <argos3/core/utility/math/range.h>
#include <argos3/core/utility/math/rng.h>
#include <cmath>

using namespace argos;

class SPLoopFunctions : public CLoopFunctions {

public:

   SPLoopFunctions() = default;
   ~SPLoopFunctions() override = default;

   void Init(TConfigurationNode& goal_node) override;
   void Reset() override;
   void Destroy() override;
   CColor GetFloorColor(const CVector2& c_position_on_plane) override;
   void PreStep() override;

private:
    CFloorEntity* m_pcFloor{};

    Real m_goalX;
    Real m_goalY;
    Real m_goalRadius;

    Real m_homeX;
    Real m_homeY;
    Real m_homeRadius;
};

#endif
