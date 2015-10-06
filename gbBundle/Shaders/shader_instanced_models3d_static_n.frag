
#if defined(__OPENGL_30__)

in vec3 v_normal;
in vec2 v_texcoord;
in mat3 v_tbn_matrix;

#else

varying vec3 v_normal;
varying vec2 v_texcoord;
varying mat3 v_tbn_matrix;

#endif

uniform sampler2D sampler_01;

void main(void)
{
    vec3 normal = (v_tbn_matrix * texture2D(sampler_01, v_texcoord).rgb + 1.0) * 0.5;
    gl_FragColor = vec4(normal, gl_FragCoord.z);
}
