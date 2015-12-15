//
//  scene_graph.h
//  gbCore
//
//  Created by sergey.sergeev on 8/26/15.
//  Copyright (c) 2015 sergey.sergeev. All rights reserved.
//

#ifndef scene_graph_h
#define scene_graph_h

#include "main_headers.h"
#include "declarations.h"
#include "i_scene_graph.h"

#define scene_graph_id 0
#define scene_graph_inst std::static_pointer_cast<gb::scene_graph>(game_scene::get_transition()->get_graph(scene_graph_id))

namespace gb
{
    class scene_graph : public i_scene_graph,
    public std::enable_shared_from_this<scene_graph>
    {
    private:
        
    protected:
        
        camera_shared_ptr m_camera;
        
        std::vector<omni_lights_instances_container_shared_ptr> m_omni_lights_containers;
        shadow_cast_light_shared_ptr m_shadow_cast_light;
        
        skybox_shared_ptr m_skybox;
        ocean_shared_ptr m_ocean;
        
        std::set<game_object_shared_ptr> m_game_objects_container;
        
        void on_update(f32 deltatime);
        
    public:
        
        scene_graph();
        ~scene_graph();
        
        omni_light_shared_ptr add_omni_light(f32 radius = 1.f, const glm::vec4& color = glm::vec4(1.f));
        void remove_omni_light(const omni_light_shared_ptr& omni_light);
        
        void set_camera(const camera_shared_ptr& camera);
        camera_shared_ptr get_camera() const;
        
        void set_shadow_cast_light(const shadow_cast_light_shared_ptr& shadow_cast_light);
        shadow_cast_light_shared_ptr get_shadow_cast_light() const;
        
        void set_skybox(const skybox_shared_ptr& skybox);
        
        void set_ocean(const ocean_shared_ptr& ocean);
        
        void add_game_object(const game_object_shared_ptr& game_object);
        void remove_game_object(const game_object_shared_ptr& game_object);
        
        //void add_omni_light(const omni_light_shared_ptr& omni_light);
        //void remove_omni_light(const omni_light_shared_ptr& omni_light);
        
        //void add_instanced_omni_lights(const instanced_omni_lights_shared_ptr& instanced_omni_lights);
        //void remove_instanced_omni_lights(const instanced_omni_lights_shared_ptr& instanced_omni_lights);
        
        //void add_direction_light(const direction_light_shared_ptr& direction_light);
        //void remove_direction_light(const direction_light_shared_ptr& direction_light);
        
        void set_box2d_world(const glm::vec2 &min_bound, const glm::vec2 &max_bound);
        
        b2Body* add_box2d_body(const std::shared_ptr<b2BodyDef> box2d_body_definition);
        void remove_box2d_body(b2Body* box2d_body);
    };
};

#endif
