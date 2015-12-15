//
//  scene_fabricator.h
//  gbCore
//
//  Created by sergey.sergeev on 8/26/15.
//  Copyright (c) 2015 sergey.sergeev. All rights reserved.
//

#ifndef scene_fabricator_h
#define scene_fabricator_h

#include "main_headers.h"
#include "declarations.h"
#include "configuration_accessor.h"
#include "i_scene_fabricator.h"

#define scene_fabricator_id 0
#define scene_fabricator_inst std::static_pointer_cast<gb::scene_fabricator>(game_scene::get_transition()->get_fabricator(scene_fabricator_id))

namespace gb
{
    class scene_fabricator : public i_scene_fabricator
    {
    private:
        
    protected:
        
        std::set<camera_shared_ptr> m_cameras_container;
        std::set<shadow_cast_light_shared_ptr> m_shadow_cast_lights_container;
        std::set<game_object_shared_ptr> m_game_objects_container;
        std::set<direction_light_shared_ptr> m_direction_lights_container;
        
        void add_materials(const renderable_game_object_shared_ptr& renderable_game_object,
                           const std::vector<std::shared_ptr<configuration>>& configurations);
        
    public:
        
        scene_fabricator();
        ~scene_fabricator();
        
        camera_shared_ptr create_camera(f32 fov, f32 near, f32 far,const glm::ivec4& viewport);
        void destroy_camera(const camera_shared_ptr& camera);
        
        direction_light_shared_ptr create_direction_light();
        void destroy_direction_light(const direction_light_shared_ptr& direction_light);
        
        shadow_cast_light_shared_ptr create_shadow_cast_light(f32 fov, f32 near, f32 far);
        void destroy_shadow_cast_light(const shadow_cast_light_shared_ptr& shadow_cast_light);
        
        skybox_shared_ptr create_skybox(const std::string& filename);
        void destroy_skybox(const skybox_shared_ptr& sky_box);
        
        ocean_shared_ptr create_ocean(const std::string& filename);
        void destroy_ocean(const ocean_shared_ptr& ocean);
        
        model3d_static_shared_ptr create_model3d_static(const std::string& filename);
        
        instanced_models3d_static_shared_ptr create_instanced_models3d_static(const std::string& filename, i32 num_instances);
        
        model3d_animated_shared_ptr create_model3d_animated(const std::string& filename);
        
        particle_emitter_shared_ptr create_particle_emitter(const std::string& filename);
        
        void destroy_game_object(const game_object_shared_ptr& game_object);
    };
};

#endif
