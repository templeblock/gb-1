//
//  game_object.cpp
//  gbCore
//
//  Created by sergey.sergeev on 8/26/15.
//  Copyright (c) 2015 sergey.sergeev. All rights reserved.
//

#include "game_object.h"
#include "ces_transformation_component.h"

namespace gb
{
    game_object::game_object()
    {
        ces_transformation_component_shared_ptr transformation_component = std::make_shared<ces_transformation_component>();
        ces_entity::add_component(transformation_component);
    }
    
    game_object::~game_object()
    {
        
    }
    
    void game_object::set_position(const glm::vec3& position)
    {
        unsafe_get_transformation_component_from_this->set_position(position);
    }
    
    glm::vec3 game_object::get_position() const
    {
        return unsafe_get_transformation_component_from_this->get_position();
    }
    
    void game_object::set_rotation(const glm::vec3& rotation)
    {
        unsafe_get_transformation_component_from_this->set_rotation(rotation);
    }
    
    glm::vec3 game_object::get_rotation() const
    {
        return unsafe_get_transformation_component_from_this->get_rotation();
    }
    
    void game_object::set_scale(const glm::vec3& scale)
    {
        unsafe_get_transformation_component_from_this->set_scale(scale);
    }
    
    glm::vec3 game_object::get_scale() const
    {
        return unsafe_get_transformation_component_from_this->get_scale();
    }
    
    glm::vec3 game_object::get_forward() const
    {
        return unsafe_get_transformation_component_from_this->get_forward();
    }
    
    glm::vec3 game_object::get_up() const
    {
        return unsafe_get_transformation_component_from_this->get_up();
    }
    
    glm::vec3 game_object::get_right() const
    {
        return unsafe_get_transformation_component_from_this->get_right();
    }
}