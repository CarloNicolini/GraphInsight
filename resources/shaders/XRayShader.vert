/* Vertex Shader */

varying vec3 P;
varying vec3 N;
varying vec3 I;

void main()
{
    //Transform vertex by modelview and projection matrices
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

    // Position in clip space
    P = vec3(gl_ModelViewMatrix * gl_Vertex);

    // Normal transform (transposed model-view inverse)
    N = gl_NormalMatrix * gl_Normal;

    // Incident vector
    I = P;

    // Forward current color and texture coordinates after applying texture matrix
    gl_FrontColor = gl_Color;
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
}

