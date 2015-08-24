//
//  material.cpp
//  gbCore
//
//  Created by sergey.sergeev on 8/13/15.
//  Copyright (c) 2015 sergey.sergeev. All rights reserved.
//

#include "material.h"

namespace gb
{
    material_cached_parameters::material_cached_parameters(void) :
    m_shader(nullptr)
    {
        std::for_each(m_textures.begin(), m_textures.end(), [](std::shared_ptr<texture>& iterator){
            iterator = nullptr;
        });
    }
    
    material_cached_parameters::~material_cached_parameters(void)
    {
        
    }
    
    std::shared_ptr<material_cached_parameters> material::m_cached_parameters = nullptr;
    std::once_flag g_cached_parameters_created;
    std::shared_ptr<material_cached_parameters> material::get_cached_parameters(void)
    {
        std::call_once(g_cached_parameters_created, []{
            m_cached_parameters = std::make_shared<material_cached_parameters>();
            m_cached_parameters->m_is_depth_test = true;
            m_cached_parameters->m_is_depth_mask = true;
            m_cached_parameters->m_is_culling = false;
            m_cached_parameters->m_is_blending = false;
        });
        return m_cached_parameters;
    }
    
    material::material(void) :
    m_parameters(std::make_shared<material_cached_parameters>())
    {
        
    }
    
    material::~material(void)
    {
        
    }
    
    std::shared_ptr<material> material::construct(const std::shared_ptr<material_configuration> &configuration)
    {
        std::shared_ptr<material> material = std::make_shared<gb::material>();
        assert(configuration != nullptr);
        
        material->set_culling(configuration->get_culling());
        material->set_culling_mode(configuration->get_culling_mode());
        
        material->set_blending(configuration->get_blending());
        material->set_blending_function_source(configuration->get_blending_function_source());
        material->set_blending_function_destination(configuration->get_blending_function_destination());
        
        material->set_depth_test(configuration->get_depth_test());
        material->set_depth_mask(configuration->get_depth_mask());
        
        material->set_clipping(configuration->get_clipping());
        material->set_clipping_plane(glm::vec4(configuration->get_clipping_x(),
                                               configuration->get_clipping_y(),
                                               configuration->get_clipping_z(),
                                               configuration->get_clipping_w()));
        
        material->set_reflecting(configuration->get_reflecting());
        material->set_shadowing(configuration->get_shadowing());
        material->set_debugging(configuration->get_debugging());

        return material;
    }
    
    
    bool material::is_culling(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_is_culling;
    }
    
    GLenum material::get_culling_mode(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_culling_mode;
    }
    
    bool material::is_blending(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_is_blending;
    }
    
    GLenum material::get_blending_function_source(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_blending_function_source;
    }
    
    GLenum material::get_blending_function_destination(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_blending_function_destination;
    }
    
    bool material::is_depth_test(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_is_depth_test;
    }
    
    bool material::is_depth_mask(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_is_depth_mask;
    }
    
    bool material::is_clipping(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_is_clipping;
    }
    
    glm::vec4 material::get_clipping_plane(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_clipping_plane;
    }
    
    bool material::is_reflecting(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_is_reflecting;
    }
    
    bool material::is_shadowing(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_is_shadowing;
    }
    
    bool material::is_debugging(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_is_debugging;
    }
    
    std::shared_ptr<shader> material::get_shader(void) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_shader;
    }
    
    std::shared_ptr<texture> material::get_texture(e_shader_sampler sampler) const
    {
        assert(m_parameters != nullptr);
        return m_parameters->m_textures.at(sampler);
    }
    
    e_shader_sampler material::get_sampler_index(const std::shared_ptr<texture>& texture) const
    {
        assert(m_parameters != nullptr);
        for(ui32 i = 0; i < m_parameters->m_textures.size(); ++i)
        {
            if(texture == m_parameters->m_textures.at(i))
            {
                return static_cast<e_shader_sampler>(i);
            }
        }
        assert(false);
        return e_shader_sampler_01;
    }
    
    void material::set_culling(bool value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_is_culling = value;
    }
    
    void material::set_culling_mode(GLenum value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_culling_mode = value;
    }
    
    void material::set_blending(bool value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_is_blending = value;
    }
    
    void material::set_blending_function_source(GLenum value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_blending_function_source = value;
    }
    
    void material::set_blending_function_destination(GLenum value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_blending_function_destination = value;
    }
    
    void material::set_depth_test(bool value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_is_depth_test = value;
    }
    
    void material::set_depth_mask(bool value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_is_depth_mask = value;
    }
    
    void material::set_clipping(bool value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_is_clipping = value;
    }
    
    void material::set_clipping_plane(const glm::vec4& value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_clipping_plane = value;
    }
    
    void material::set_reflecting(bool value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_is_reflecting = value;
    }
    
    void material::set_shadowing(bool value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_is_shadowing = value;
    }
    
    void material::set_debugging(bool value)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_is_debugging = value;
    }
    
    void material::set_shader(const std::shared_ptr<shader>& shader)
    {
        assert(m_parameters != nullptr);
        
        m_parameters->m_shader = shader;
    }
    
    void material::set_texture(const std::shared_ptr<texture>& texture,
                               e_shader_sampler sampler)
    {
        assert(m_parameters != nullptr);
        m_parameters->m_textures.at(sampler) = texture;
    }
    
    void material::set_custom_shader_uniform(const glm::mat4x4& matrix, const std::string& uniform)
    {
        const auto& iterator = m_custom_shader_uniforms.find(uniform);
        std::shared_ptr<shader_uniform> current_uniform = nullptr;
        if(iterator != m_custom_shader_uniforms.end())
        {
            current_uniform = iterator->second;
        }
        else
        {
            current_uniform = std::make_shared<shader_uniform>(e_uniform_type_mat4);
            m_custom_shader_uniforms.insert(std::make_pair(uniform, current_uniform));
        }
        current_uniform->set_mat4(matrix);
    }
    
    void material::set_custom_shader_uniform(const glm::mat3x3& matrix, const std::string& uniform)
    {
        const auto& iterator = m_custom_shader_uniforms.find(uniform);
        std::shared_ptr<shader_uniform> current_uniform = nullptr;
        if(iterator != m_custom_shader_uniforms.end())
        {
            current_uniform = iterator->second;
        }
        else
        {
            current_uniform = std::make_shared<shader_uniform>(e_uniform_type_mat3);
            m_custom_shader_uniforms.insert(std::make_pair(uniform, current_uniform));
        }
        current_uniform->set_mat3(matrix);
    }
    
    void material::set_custom_shader_uniform(const glm::vec4& vector, const std::string& uniform)
    {
        const auto& iterator = m_custom_shader_uniforms.find(uniform);
        std::shared_ptr<shader_uniform> current_uniform = nullptr;
        if(iterator != m_custom_shader_uniforms.end())
        {
            current_uniform = iterator->second;
        }
        else
        {
            current_uniform = std::make_shared<shader_uniform>(e_uniform_type_vec4);
            m_custom_shader_uniforms.insert(std::make_pair(uniform, current_uniform));
        }
        current_uniform->set_vec4(vector);
    }
    
    void material::set_custom_shader_uniform(const glm::vec3& vector, const std::string& uniform)
    {
        const auto& iterator = m_custom_shader_uniforms.find(uniform);
        std::shared_ptr<shader_uniform> current_uniform = nullptr;
        if(iterator != m_custom_shader_uniforms.end())
        {
            current_uniform = iterator->second;
        }
        else
        {
            current_uniform = std::make_shared<shader_uniform>(e_uniform_type_vec3);
            m_custom_shader_uniforms.insert(std::make_pair(uniform, current_uniform));
        }
        current_uniform->set_vec3(vector);
    }
    
    void material::set_custom_shader_uniform(const glm::vec2& vector, const std::string& uniform)
    {
        const auto& iterator = m_custom_shader_uniforms.find(uniform);
        std::shared_ptr<shader_uniform> current_uniform = nullptr;
        if(iterator != m_custom_shader_uniforms.end())
        {
            current_uniform = iterator->second;
        }
        else
        {
            current_uniform = std::make_shared<shader_uniform>(e_uniform_type_vec2);
            m_custom_shader_uniforms.insert(std::make_pair(uniform, current_uniform));
        }
        current_uniform->set_vec2(vector);
    }
    
    void material::set_custom_shader_uniform(f32 value, const std::string& uniform)
    {
        const auto& iterator = m_custom_shader_uniforms.find(uniform);
        std::shared_ptr<shader_uniform> current_uniform = nullptr;
        if(iterator != m_custom_shader_uniforms.end())
        {
            current_uniform = iterator->second;
        }
        else
        {
            current_uniform = std::make_shared<shader_uniform>(e_uniform_type_f32);
            m_custom_shader_uniforms.insert(std::make_pair(uniform, current_uniform));
        }
        current_uniform->set_f32(value);
    }
    
    void material::set_custom_shader_uniform(i32 value, const std::string& uniform)
    {
        const auto& iterator = m_custom_shader_uniforms.find(uniform);
        std::shared_ptr<shader_uniform> current_uniform = nullptr;
        if(iterator != m_custom_shader_uniforms.end())
        {
            current_uniform = iterator->second;
        }
        else
        {
            current_uniform = std::make_shared<shader_uniform>(e_uniform_type_i32);
            m_custom_shader_uniforms.insert(std::make_pair(uniform, current_uniform));
        }
        current_uniform->set_i32(value);
    }
    
    const std::map<std::string, std::shared_ptr<shader_uniform>>& material::get_custom_uniforms(void) const
    {
        return m_custom_shader_uniforms;
    }
    
    void material::bind(void)
    {
        assert(m_parameters != nullptr);
        assert(m_parameters->m_shader != nullptr);
        
        m_parameters->m_shader->bind();
        
        for(ui32 i = 0; i < e_shader_sampler_max; ++i)
        {
            if(m_parameters->m_textures[i] != nullptr)
            {
                m_parameters->m_shader->set_texture(m_parameters->m_textures[i], static_cast<e_shader_sampler>(i));
            }
        }
        
        if(m_parameters->m_is_depth_test &&
           material::get_cached_parameters()->m_is_depth_test != m_parameters->m_is_depth_test)
        {
            gl_enable(GL_DEPTH_TEST);
            gl_depth_function(GL_LEQUAL);
            material::get_cached_parameters()->m_is_depth_test = m_parameters->m_is_depth_test;
        }
        else if(material::get_cached_parameters()->m_is_depth_test != m_parameters->m_is_depth_test)
        {
            gl_disable(GL_DEPTH_TEST);
            material::get_cached_parameters()->m_is_depth_test = m_parameters->m_is_depth_test;
        }
        
        if(m_parameters->m_is_depth_mask &&
           material::get_cached_parameters()->m_is_depth_mask != m_parameters->m_is_depth_mask)
        {
            gl_depth_mask(GL_TRUE);
            material::get_cached_parameters()->m_is_depth_mask = m_parameters->m_is_depth_mask;
        }
        else if(material::get_cached_parameters()->m_is_depth_mask != m_parameters->m_is_depth_mask)
        {
            gl_depth_mask(GL_FALSE);
            material::get_cached_parameters()->m_is_depth_mask = m_parameters->m_is_depth_mask;
        }
        
        if(m_parameters->m_is_culling &&
           material::get_cached_parameters()->m_is_culling != m_parameters->m_is_culling)
        {
            gl_enable(GL_CULL_FACE);
            gl_cull_face(m_parameters->m_culling_mode);
            material::get_cached_parameters()->m_is_culling = m_parameters->m_is_culling;
        }
        else if(material::get_cached_parameters()->m_is_culling != m_parameters->m_is_culling)
        {
            gl_disable(GL_CULL_FACE);
            material::get_cached_parameters()->m_is_culling = m_parameters->m_is_culling;
        }
        
        if(m_parameters->m_is_blending &&
           material::get_cached_parameters()->m_is_blending != m_parameters->m_is_blending)
        {
            gl_enable(GL_BLEND);
            gl_blend_function(m_parameters->m_blending_function_source, m_parameters->m_blending_function_destination);
            material::get_cached_parameters()->m_is_blending = m_parameters->m_is_blending;
        }
        else if(material::get_cached_parameters()->m_is_blending != m_parameters->m_is_blending)
        {
            gl_disable(GL_BLEND);
            material::get_cached_parameters()->m_is_blending = m_parameters->m_is_blending;
        }
        
        if(m_parameters->m_is_clipping &&
           material::get_cached_parameters()->m_is_clipping != m_parameters->m_is_clipping)
        {
#if defined(__IOS__) && defined(GL_APPLE_clip_distance)
            gl_enable(GL_CLIP_DISTANCE0_APPLE);
#else
            gl_enable(GL_CLIP_DISTANCE0);
#endif
            material::get_cached_parameters()->m_is_clipping = m_parameters->m_is_clipping;
        }
        else if(material::get_cached_parameters()->m_is_clipping != m_parameters->m_is_clipping)
        {
#if defined(__IOS__) && defined(GL_APPLE_clip_distance)
            gl_disable(GL_CLIP_DISTANCE0_APPLE);
#else
            gl_disable(GL_CLIP_DISTANCE0);
#endif
            material::get_cached_parameters()->m_is_clipping = m_parameters->m_is_clipping;
        }
    }
    
    void material::unbind(void)
    {
        assert(m_parameters != nullptr);
        assert(m_parameters->m_shader != nullptr);
        m_parameters->m_shader->unbind();
    }
}