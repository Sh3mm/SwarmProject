#ifndef SWARM_PROJECT_FUNCTIONS_H
#define SWARM_PROJECT_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/core/simulator/entity/floor_entity.h>
#include <argos3/core/utility/math/range.h>
#include <argos3/core/utility/math/rng.h>

using namespace argos;

class SPLoopFunctions : public CLoopFunctions {

public:

   SPLoopFunctions() = default;
   ~SPLoopFunctions() override = default;

   void Init(TConfigurationNode& t_tree) override;
   void Reset() override;
   void Destroy() override;
   CColor GetFloorColor(const CVector2& c_position_on_plane) override;
   void PreStep() override;

private:
      CFloorEntity* m_pcFloor{};
};

#endif
