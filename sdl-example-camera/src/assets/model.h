class Plane
{
	public:
		void draw()
		{
			glPushMatrix();
			glRotatef(0.f, 0.f, 0.f, 0.f);
			glTranslatef(0.f, 0.f, 0.f);
			glBegin(GL_QUADS);
				glColor3f(0.8f, 0.8f, 0.8f);
				glVertex3f(-1.f, -1.f, -1.f);
				glVertex3f(1.f, -1.f, -1.f);
				glVertex3f(1.f, -1.f, 1.f);
				glVertex3f(-1.f, -1.f, 1.f);
			glEnd();
			glPopMatrix();
		}
};

class Cube
{
	private:
		float m_angle = 0;
		bool m_placed = false;
	public:
	void update()
	{	
		if(!m_placed)
			glTranslatef(0.f, 0.f, -1.33f);
		m_placed = true;

		m_angle += 0.4;
		glPushMatrix();	
		glRotatef(m_angle, 1.f, 0.f, 0.f);
		glRotatef(m_angle, 0.f, 1.f, 0.f);
		glRotatef(m_angle, 0.f, 0.f, 1.f);
		draw();
		glPopMatrix();
	}
	void draw()
	{
		glBegin(GL_QUADS);
	 
			// Top face
		  	glColor3f(   1.f, 0.f,  1.f );  // Pink
		  	glVertex3f(  .35f, .35f, -.35f );  // Top-right of top face
		  	glVertex3f( -.35f, .35f, -.35f );  // Top-left of top face
		  	glVertex3f( -.35f, .35f,  .35f );  // Bottom-left of top face
		 	glVertex3f(  .35f, .35f,  .35f );  // Bottom-right of top face
		 
			// Bottom face
			glColor3f(   .0f,  1.f,  .0f ); // Green
			glVertex3f(  .35f, -.35f, -.35f ); // Top-right of bottom face
			glVertex3f( -.35f, -.35f, -.35f ); // Top-left of bottom face
			glVertex3f( -.35f, -.35f,  .35f ); // Bottom-left of bottom face
			glVertex3f(  .35f, -.35f,  .35f ); // Bottom-right of bottom face
		 
			// Front face
			glColor3f(   .0f,  .0f, 1.f );  // Blue
			glVertex3f(  .35f,  .35f, .35f );  // Top-Right of front face
			glVertex3f( -.35f,  .35f, .35f );  // Top-left of front face
			glVertex3f( -.35f, -.35f, .35f );  // Bottom-left of front face
			glVertex3f(  .35f, -.35f, .35f );  // Bottom-right of front face
		 
			// Back face
			glColor3f(   1.f,  1.f,  0.f ); // Yellow
			glVertex3f(  .35f, -.35f, -.35f ); // Bottom-Left of back face
			glVertex3f( -.35f, -.35f, -.35f ); // Bottom-Right of back face
			glVertex3f( -.35f,  .35f, -.35f ); // Top-Right of back face
			glVertex3f(  .35f,  .35f, -.35f ); // Top-Left of back face
		 
			// Left face
			glColor3f(   0.f,  1.f,  1.f);  // Cyan
			glVertex3f( -.35f,  .35f,  .35f);  // Top-Right of left face
			glVertex3f( -.35f,  .35f, -.35f);  // Top-Left of left face
			glVertex3f( -.35f, -.35f, -.35f);  // Bottom-Left of left face
			glVertex3f( -.35f, -.35f,  .35f);  // Bottom-Right of left face
		 
			// Right face
			glColor3f(   1.f,  0.f,  0.f);  // Red
			glVertex3f(  .35f,  .35f,  .35f);  // Top-Right of left face
			glVertex3f(  .35f,  .35f, -.35f);  // Top-Left of left face
			glVertex3f(  .35f, -.35f, -.35f);  // Bottom-Left of left face
			glVertex3f(  .35f, -.35f,  .35f);  // Bottom-Right of left face
		
		// End of GL calls
		glEnd();
	}
};
