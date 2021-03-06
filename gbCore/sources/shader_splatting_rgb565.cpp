//
//  shader_splatting_textures.cpp
//  gbCore
//
//  Created by sergey.sergeev on 11/6/15.
//  Copyright © 2015 sergey.sergeev. All rights reserved.
//

#include "main_headers.h"

const char* shader_splatting_rgb565_vert = string_shader
(
#if defined(__OPENGL_30__)
 
 out vec2 v_texcoord;
 out vec2 v_texcoord_scaled;
 
#else
 
 varying vec2 v_texcoord;
 varying vec2 v_texcoord_scaled;
 
#endif
 
 const float k_texcoord_scale = 8.0;
 
 void main(void)
{
    v_texcoord = a_texcoord;
    v_texcoord_scaled = v_texcoord * k_texcoord_scale;
    
    gl_Position = vec4(a_position, 1.0);
}
 );

const char* shader_splatting_rgb565_frag = string_shader
(
#if defined(__OPENGL_30__)
 
 in vec2 v_texcoord;
 in vec2 v_texcoord_scaled;
 
#else
 
 varying vec2 v_texcoord;
 varying vec2 v_texcoord_scaled;
 
#endif
 
 uniform sampler2D  sampler_01;
 uniform sampler2D  sampler_02;
 uniform sampler2D  sampler_03;
 uniform sampler2D  sampler_04;
 
 void main()
{
    vec4 splatting_color = texture2D(sampler_01, v_texcoord);
    vec4 diffuse_color = vec4(0.0, 0.0, 0.0, 1.0);
    
    if(splatting_color.x > 0.0)
    {
        diffuse_color = diffuse_color + texture2D(sampler_02, v_texcoord_scaled) * splatting_color.x;
    }
    if(splatting_color.y > 0.0)
    {
        diffuse_color = diffuse_color + texture2D(sampler_03, v_texcoord_scaled) * splatting_color.y;
    }
    if(splatting_color.z > 0.0)
    {
        diffuse_color = diffuse_color + texture2D(sampler_04, v_texcoord_scaled) * splatting_color.z;
    }
    
    gl_FragColor = diffuse_color;
}
 );