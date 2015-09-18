
/* Fragment Shader */

varying vec3 P;
varying vec3 N;
varying vec3 I;

uniform float EdgeFalloff;

void main()
{
    float opacity = dot(normalize(N), normalize(-I));
    opacity = abs(opacity);
    EdgeFalloff =  length(N);
    opacity = 1.0 - pow(opacity, EdgeFalloff);

    gl_FragColor = opacity * gl_Color;
}
