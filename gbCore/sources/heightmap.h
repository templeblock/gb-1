//
//  heightmap.h
//  gbCore
//
//  Created by sergey.sergeev on 11/9/15.
//  Copyright © 2015 sergey.sergeev. All rights reserved.
//

#ifndef heightmap_h
#define heightmap_h

#include "ces_entity.h"
#include "heightmap_texture_generator.h"

namespace gb
{
    class heightmap : public ces_entity
    {
    private:
        
        std::weak_ptr<scene_graph> m_scene_graph;
        
    protected:
        
        void set_scene_graph(const scene_graph_shared_ptr& scene_graph);
        scene_graph_shared_ptr get_scene_graph() const;
        
    public:
        
        heightmap(const std::string& filename);
        ~heightmap();
        
        void set_position(const glm::vec3& position);
        glm::vec3 get_position() const;
        
        void on_added_to_scene(const scene_graph_shared_ptr& scene_graph);
        void on_removed_from_scene();
        
        void add_material(const std::string& technique_name, i32 technique_pass, const material_shared_ptr& material);
        
        void set_splatting_diffuse_textures(const std::array<texture_shared_ptr, heightmap_texture_generator::e_splatting_texture_max>& splatting_diffuse_textures);
        void set_splatting_normal_textures(const std::array<texture_shared_ptr, heightmap_texture_generator::e_splatting_texture_max>& splatting_normal_textures);
        void set_splatting_displace_textures(const std::array<texture_shared_ptr, heightmap_texture_generator::e_splatting_texture_max>& splatting_displace_textures);
    };
};

#endif
