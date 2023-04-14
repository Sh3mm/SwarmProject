#include "SwarmProject.h"
#include "buzz_utils.h"

/****************************************/
/****************************************/

void SPLoopFunctions::Init(TConfigurationNode& t_node) {
    m_pcFloor = &GetSpace().GetFloorEntity();
    auto data_node = GetNode(t_node, "data");
    auto poi_node = GetNode(data_node, "POI_AREA");

    auto goal_node = GetNode(poi_node, "GOAL");
    GetNodeAttributeOrDefault(goal_node, "X", m_goalX, 0.);
    GetNodeAttributeOrDefault(goal_node, "Y", m_goalY, 0.);
    GetNodeAttributeOrDefault(goal_node, "RADIUS", m_goalRadius, 0.);

    auto home_node = GetNode(poi_node, "HOME");
    GetNodeAttributeOrDefault(home_node, "X", m_homeX, 0.);
    GetNodeAttributeOrDefault(home_node, "Y", m_homeY, 0.);
    GetNodeAttributeOrDefault(home_node, "RADIUS", m_homeRadius, 1.);

    for (const auto &item: GetSimulator().GetSpace().GetEntitiesByType("kheperaiv")){
        auto khepera = any_cast<CKheperaIVEntity*>(item.second);
        buzzvm_t buzzController = dynamic_cast<CBuzzControllerKheperaIV&>(
                    khepera->GetControllableEntity().GetController()
                ).GetBuzzVM();

        buzzobj_t data = create_buzz_obj(data_node, buzzController);
        Register(buzzController, "WORLD_DATA", data);
    }
}

buzzobj_t SPLoopFunctions::create_buzz_obj(TConfigurationNode &node, buzzvm_t buzz_vm) {
    buzzobj_t data = buzzheap_newobj(buzz_vm, BUZZTYPE_TABLE);

    // attribute loop
    auto attribute = node.FirstAttribute(false);
    while(attribute != nullptr){
        std::string name;
        Real realValue;
        std::string stringValue;

        // getting attribute name and value
        attribute->GetName(&name);
        try {
            // putting the attribute in the table
            attribute->GetValue(&realValue);
            TablePut(buzz_vm, data, name, realValue);
        } catch (ticpp::Exception &e) {
            attribute->GetValue(&stringValue);
            TablePut(buzz_vm, data, name, stringValue);
        }
        // iterate as long as there are more attributes
        attribute = attribute->Next(false);
    }

    TConfigurationNode* child = node.FirstChildElement(false);
    while(child != nullptr){
        std::string name;
        child->GetValue(&name);

        auto obj = create_buzz_obj(*child, buzz_vm);
        TablePut(buzz_vm, data, name, obj);

        // iterate as long as there are more children
        child = child->NextSiblingElement(false);
    }

    return data;
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
