#include "SwarmProject.h"
#include "buzz_utils.h"

/****************************************/
/****************************************/

void SPLoopFunctions::Init(TConfigurationNode& t_node) {
    m_pcFloor = &GetSpace().GetFloorEntity();

    auto goal_node = GetNode(t_node, "goal");
    GetNodeAttributeOrDefault(goal_node, "x", m_goalX, 0.);
    GetNodeAttributeOrDefault(goal_node, "y", m_goalY, 0.);
    GetNodeAttributeOrDefault(goal_node, "radius", m_goalRadius, 0.);

    auto home_node = GetNode(t_node, "home");
    GetNodeAttributeOrDefault(home_node, "x", m_homeX, 0.);
    GetNodeAttributeOrDefault(home_node, "y", m_homeY, 0.);
    GetNodeAttributeOrDefault(home_node, "radius", m_homeRadius, 1.);

    for (const auto &item: GetSimulator().GetSpace().GetEntitiesByType("kheperaiv")){
        auto khepera = any_cast<CKheperaIVEntity*>(item.second);
        buzzvm_t buzzController = dynamic_cast<CBuzzControllerKheperaIV&>(
                    khepera->GetControllableEntity().GetController()
                ).GetBuzzVM();

        buzzobj_t goal_data = buzzheap_newobj(buzzController, BUZZTYPE_TABLE);
        TablePut(buzzController, goal_data, "x", m_goalX);
        TablePut(buzzController, goal_data, "y", m_goalY);
        TablePut(buzzController, goal_data, "radius", m_goalRadius);
        Register(buzzController, "goal", goal_data);
    }
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

    const Real y = c_position_on_plane.GetY();
    const Real x = c_position_on_plane.GetX();

    if( // Home Area
            (x < m_homeX + m_homeRadius && x > m_homeX - m_homeRadius) &&
            (y < m_homeY + m_homeRadius && y > m_homeY - m_homeRadius)
    ) { return CColor::BLUE; }

    const Real dy = y - m_goalY;
    const Real dx = x - m_goalX;

    const Real dist = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));

    if( // Goal Area
            dist < m_goalRadius
    ) { return CColor::GREEN; }

    //default
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
