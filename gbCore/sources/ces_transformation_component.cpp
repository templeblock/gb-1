//
//  ces_transformation_component.cpp
//  gbCore
//
//  Created by sergey.sergeev on 8/17/15.
//  Copyright (c) 2015 sergey.sergeev. All rights reserved.
//

#include "ces_transformation_component.h"

namespace gb
{
    ces_transformation_component::ces_transformation_component(void) :
    m_is_matrix_m_computed(false)
    {
        m_type = e_ces_component_type_transformation;
        ces_transformation_component::set_position(glm::vec3(0.f));
        ces_transformation_component::set_rotation(glm::vec3(0.f));
        ces_transformation_component::set_scale(glm::vec3(1.f));
    }
    
    ces_transformation_component::~ces_transformation_component(void)
    {
        
    }
    
    void ces_transformation_component::set_position(const glm::vec3& position)
    {
        m_position = position;
        m_matrix_t = glm::translate(glm::mat4(1.f), m_position);
        m_is_matrix_m_computed = false;
    }
    
    void ces_transformation_component::set_rotation(const glm::vec3& rotation)
    {
        m_rotation = rotation;
        m_matrix_r = glm::rotate(glm::mat4(1.f), m_rotation.x, glm::vec3(1.f, 0.f, 0.f));
        m_matrix_r = glm::rotate(m_matrix_r, m_rotation.z, glm::vec3(0.f, 0.f, 1.f));
        m_matrix_r = glm::rotate(m_matrix_r, m_rotation.y, glm::vec3(0.f, 1.f, 0.f));
        m_is_matrix_m_computed = false;
    }
    
    void ces_transformation_component::set_scale(const glm::vec3& scale)
    {
        m_scale = scale;
        m_matrix_s = glm::scale(glm::mat4(1.f), m_scale);
        m_is_matrix_m_computed = false;
    }
    
    glm::vec3 ces_transformation_component::get_position(void) const
    {
        return m_position;
    }
    
    glm::vec3 ces_transformation_component::get_rotation(void) const
    {
        return m_rotation;
    }
    
    glm::vec3 ces_transformation_component::get_scale(void) const
    {
        return m_scale;
    }
    
    glm::mat4 ces_transformation_component::get_matrix_m(void)
    {
        if(!m_is_matrix_m_computed)
        {
            m_matrix_m = m_matrix_t * m_matrix_r * m_matrix_s;
            m_is_matrix_m_computed = true;
        }
        return m_matrix_m;
    }
    
    glm::vec3 ces_transformation_component::get_forward(void) const
    {
        glm::vec4 vector = m_matrix_m[2];
        vector = glm::normalize(vector);
        return glm::vec3(vector.x, vector.y, vector.z);
    }
    
    glm::vec3 ces_transformation_component::get_up(void) const
    {
        glm::vec4 vector = m_matrix_m[1];
        vector = glm::normalize(vector);
        return glm::vec3(vector.x, vector.y, vector.z);
    }
    
    glm::vec3 ces_transformation_component::get_right(void) const
    {
        glm::vec4 vector = m_matrix_m[0];
        vector = glm::normalize(vector);
        return glm::vec3(vector.x, vector.y, vector.z);
    }
}
