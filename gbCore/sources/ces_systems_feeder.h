//
//  systems_feeder.h
//  gbCore
//
//  Created by Sergey Sergeev on 8/13/15.
//  Copyright (c) 2015 sergey.sergeev. All rights reserved.
//

#ifndef systems_feeder_h
#define systems_feeder_h

#include "ces_systems_feeder.h"
#include "game_loop.h"
#include "ces_system_types.h"

namespace gb
{
    class ces_system;
    class ces_entity;
    class ces_systems_feeder : public i_game_loop
    {
    private:
        
    protected:
        
        std::map<i32, std::shared_ptr<ces_system>> m_systems;
        std::set<std::shared_ptr<ces_entity>> m_entities;
        
        void on_update(f32 deltatime);
        
    public:
        
        ces_systems_feeder();
        ~ces_systems_feeder();
        
        void add_system(const std::shared_ptr<ces_system>& system, i32 type);
        void remove_system(i32 type);
        
        void add_entity(const std::shared_ptr<ces_entity>& entity);
        void remove_entity(const std::shared_ptr<ces_entity>& entity);
        
        std::shared_ptr<ces_system> get_system(i32 type) const;
    };
};

#endif
