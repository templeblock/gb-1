
#if defined(__OPENGL_30__)

out vec4 v_position;

#else

varying vec4 v_position;

#endif

uniform mat4 u_mat_m;
uniform mat4 u_mat_bones[32];
uniform vec4 u_vec_clip;
uniform mat4 u_mat_global_light_p;
uniform mat4 u_mat_global_light_v;

void main(void)
{
    vec4 position = vec4(a_position, 1.0);
    vec4 weights = a_extra / 255.0;
    
    int index = 0;
    vec4 bone_position = vec4(0.0);
    
    for(int i = 0; i < 4; i++)
    {
        index = int(a_color[i]);
        bone_position += u_mat_bones[index] * position * weights[i];
    }
    position = bone_position;
    
    position = u_mat_m * position;
    gl_Position = u_mat_global_light_p * u_mat_global_light_v * position;
    gl_ClipDistance[0] = dot(position.xyz, u_vec_clip.xyz);
    v_position = position;
}
