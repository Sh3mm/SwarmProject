#include "SwarmProject.h"
#include <argos3/core/simulator/simulator.h>
#include <argos3/core/utility/configuration/argos_configuration.h>

/****************************************/
/****************************************/

void SPLoopFunctions::Init(TConfigurationNode& t_node) {
     m_pcFloor = &GetSpace().GetFloorEntity();
}

/****************************************/
/****************************************/

void SPLoopFunctions::Reset() {

}

/****************************************/
/****************************************/

void SPLoopFunctions::Destroy() {
    /* Close the file */

}

/****************************************/
/****************************************/

CColor SPLoopFunctions::GetFloorColor(const CVector2& c_position_on_plane) {
    if( // center or starting zone
        (c_position_on_plane.GetY() > -1.0f && c_position_on_plane.GetY() < 1.0f) &&
        (c_position_on_plane.GetX() > -1.0f && c_position_on_plane.GetX() < 1.0f)
    ) {
        return CColor::BLUE;
    }

    return CColor::WHITE;
}

/****************************************/
/****************************************/

void SPLoopFunctions::PreStep() {
    m_pcFloor->SetChanged();
}

/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(SPLoopFunctions, "SP_loop_functions")
