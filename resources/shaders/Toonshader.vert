varying vec3 normal;
	
void main()
{
	normal = inverse(gl_NormalMatrix) * gl_Normal;
	gl_Position = ftransform();
	
}
