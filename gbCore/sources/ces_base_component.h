//
//  ces_base_component.h
//  gbCore
//
//  Created by sergey.sergeev on 8/11/15.
//  Copyright (c) 2015 sergey.sergeev. All rights reserved.
//

#ifndef ces_base_component_h
#define ces_base_component_h

#include "main_headers.h"
#include "ces_component_types.h"

namespace gb
{
    class ces_base_component;
    class ces_base_component_interface
    {
    private:
        
    protected:
        
        e_ces_component_type m_type;
        
        virtual void on_component_added(const std::shared_ptr<ces_base_component>& component);
        virtual void on_component_removed(const std::shared_ptr<ces_base_component>& component);
        
    public:
        
        ces_base_component_interface(void);
        virtual ~ces_base_component_interface(void) = default;
        
        e_ces_component_type get_type(void) const;
    };
    
    class ces_base_component : public std::enable_shared_from_this<ces_base_component>
    {
    private:
        
    protected:
        
        e_ces_component_type m_type;
        std::set<std::shared_ptr<ces_base_component_interface>> m_listeners;
        bool m_dirty;
        
    public:
        ces_base_component(void);
        virtual ~ces_base_component(void) = default;
        
        virtual e_ces_component_type get_type(void) const;
        virtual bool is_dirty(void) const;
        
        void add_listener(const std::shared_ptr<ces_base_component_interface>& listener);
        void remove_listener(const std::shared_ptr<ces_base_component_interface>& listener);
    };
};

#endif
