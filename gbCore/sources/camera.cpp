//
//  camera.cpp
//  gbCore
//
//  Created by sergey.sergeev on 8/17/15.
//  Copyright (c) 2015 sergey.sergeev. All rights reserved.
//

#include "camera.h"

namespace gb
{
    camera::camera(f32 fov, f32 near, f32 far, glm::ivec4 viewport) :
    m_fov(fov),
    m_near(near),
    m_far(far),
    m_rotation(0.0),
    m_viewport(viewport)
    {
        m_aspect = static_cast<f32>(viewport.z) / static_cast<f32>(viewport.w);
        m_matrix_p = glm::perspective(m_fov, m_aspect, m_near, m_far);
        m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    }
    
    camera::~camera(void)
    {
        
    }
    
    void camera::update(f32 deltatime)
    {
        m_position.y = m_distance.y;
        m_position.x = m_look_at.x + cosf(-m_rotation) * -m_distance.x;
        m_position.z = m_look_at.z + sinf(-m_rotation) * -m_distance.z;
        m_matrix_v = glm::lookAt(m_position, m_look_at, m_up);
        
        glm::vec3 position = m_position;
        position.y = -position.y;
        glm::vec3 look_at = m_look_at;
        look_at.y = -look_at.y;
        m_matrix_iv = glm::lookAt(position, look_at, m_up * -1.0f);
        
        m_matrix_n = glm::inverse(m_matrix_v);
        m_matrix_n = glm::transpose(m_matrix_n);
        
        m_matrix_vp = m_matrix_p * m_matrix_v;
        m_matrix_ivp = m_matrix_p * m_matrix_iv;
    }
    
    glm::mat4x4 camera::get_matrix_c(const glm::vec3 &position)
    {
        glm::vec3 direction = m_position - position;
        direction = glm::normalize(direction);
        
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 right = glm::cross(direction, up);
        right = glm::normalize(right);
        direction = glm::cross(right, direction);
        
        glm::mat4x4 matrix_c;
        matrix_c[0][0] = right.x;
        matrix_c[0][1] = right.y;
        matrix_c[0][2] = right.z;
        matrix_c[0][3] = 0.0f;
        matrix_c[1][0] = up.x;
        matrix_c[1][1] = up.y;
        matrix_c[1][2] = up.z;
        matrix_c[1][3] = 0.0f;
        matrix_c[2][0] = direction.x;
        matrix_c[2][1] = direction.y;
        matrix_c[2][2] = direction.z;
        matrix_c[2][3] = 0.0f;
        
        matrix_c[3][0] = position.x;
        matrix_c[3][1] = position.y;
        matrix_c[3][2] = position.z;
        matrix_c[3][3] = 1.0f;
        
        return matrix_c;
    }
    
    glm::mat4x4 camera::get_matrix_s(const glm::vec3 &position)
    {
        glm::vec3 direction = position - m_position;
        direction = glm::normalize(direction);
        
        glm::vec3 up = glm::vec3(m_matrix_v[1][0],
                                 m_matrix_v[1][1],
                                 m_matrix_v[1][2]);
        up = glm::normalize(up);
        
        glm::vec3 right = glm::cross(direction, up);
        right = glm::normalize(right);
        
        up = glm::cross(direction, right);
        up = glm::normalize(up);
        
        glm::mat4x4 matrix_s;
        matrix_s[0][0] = right.x;
        matrix_s[0][1] = right.y;
        matrix_s[0][2] = right.z;
        matrix_s[0][3] = 0.0f;
        matrix_s[1][0] = up.x;
        matrix_s[1][1] = up.y;
        matrix_s[1][2] = up.z;
        matrix_s[1][3] = 0.0f;
        matrix_s[2][0] = direction.x;
        matrix_s[2][1] = direction.y;
        matrix_s[2][2] = direction.z;
        matrix_s[2][3] = 0.0f;
        
        matrix_s[3][0] = position.x;
        matrix_s[3][1] = position.y;
        matrix_s[3][2] = position.z;
        matrix_s[3][3] = 1.0f;
        
        return matrix_s;
    }
}