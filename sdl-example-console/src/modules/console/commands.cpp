#include "commands.h"

void nullCommand(std::string p_argument){}

void printToConsole(std::string p_argument){std::cout << "[INFO]: Message sent from program: " << p_argument << std::endl;}

void gluFunction(std::string p_argument)
{	
	if(p_argument.find("gluPerspective") != std::string::npos)
	{
		float fov = 75.f;
		if(p_argument.find("reset") != std::string::npos)
			gluPerspective(75.f, 1.f, .1f, 500.f);
		if(p_argument.find("increase") != std::string::npos)
		{
			fov += 10.f;
			gluPerspective(fov, 1.f, .1f, 500.f);
		}	
		if(p_argument.find("decrease") != std::string::npos)
		{
			fov -= 10.f;
			gluPerspective(fov, 1.f, .1f, 500.f);
		}
	}
}

void objFunction(std::string p_argument)
{
	if(p_argument.find("SetPos") != std::string::npos)
	{
		if(p_argument.find("reset") != std::string::npos)
		{
			for(unsigned int i = 0; i < GameObject::getAllObjects().size(); i++)
			{
				GameObject::getAllObjects()[i] -> SetPos(0.f, 0.f, 0.f);	
				std::cout << "[INFO]: Resetting positions of object " << i << std::endl;
			}
		}
	}
	if(p_argument.find("GetPos") != std::string::npos)
	{
		for(unsigned int i = 0; i < GameObject::getAllObjects().size(); i++)
		{
			std::cout << "[INFO]: X pos of object " << i << " : " <<  GameObject::getAllObjects()[i] -> GetPos('x') << std::endl;
			std::cout << "[INFO]: Y pos of object " << i << " : " << GameObject::getAllObjects()[i] -> GetPos('y') << std::endl;
			std::cout << "[INFO]: Z pos of object " << i << " : " << GameObject::getAllObjects()[i] -> GetPos('z') << std::endl;
		}
	}
	//	if(p_argument.find("x") != std::string::npos)
	//	{
	//		if(p_argument.find("increase") != std::string::npos)
	//			GameObject::getAllObject()[i] -> SetPos()
	//	}
}


void glFunction(std::string p_argument)
{	
	if(p_argument.find("glPolygonMode") != std::string::npos)
	{
		if(p_argument.find("GL_LINE") != std::string::npos)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		if(p_argument.find("GL_POINT") != std::string::npos)
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		if(p_argument.find("GL_FILL") != std::string::npos)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if(p_argument.find("glEnable") != std::string::npos)
	{
		if(p_argument.find("GL_ALPHA_TEST") != std::string::npos)
			glEnable(GL_ALPHA_TEST);	
		if(p_argument.find("GL_AUTO_NORMAL") != std::string::npos)
			glEnable(GL_AUTO_NORMAL);
		if(p_argument.find("GL_BLEND") != std::string::npos)
			glEnable(GL_BLEND);
		if(p_argument.find("GL_CULL_FACE") != std::string::npos)
			glEnable(GL_CULL_FACE);
		if(p_argument.find("GL_DEPTH_TEST") != std::string::npos)
			glEnable(GL_DEPTH_TEST);
		if(p_argument.find("GL_DITHER") != std::string::npos)
			glEnable(GL_DITHER);
		if(p_argument.find("GL_FOG") != std::string::npos)
			glEnable(GL_FOG);
	}
	if(p_argument.find("glDisable") != std::string::npos)
	{
		if(p_argument.find("GL_ALPHA_TEST") != std::string::npos)
			glDisable(GL_ALPHA_TEST);	
		if(p_argument.find("GL_AUTO_NORMAL") != std::string::npos)
			glDisable(GL_AUTO_NORMAL);
		if(p_argument.find("GL_BLEND") != std::string::npos)
			glDisable(GL_BLEND);
		if(p_argument.find("GL_CULL_FACE") != std::string::npos)
			glDisable(GL_CULL_FACE);
		if(p_argument.find("GL_DEPTH_TEST") != std::string::npos)
			glDisable(GL_DEPTH_TEST);
		if(p_argument.find("GL_DITHER") != std::string::npos)
			glDisable(GL_DITHER);
		if(p_argument.find("GL_FOG") != std::string::npos)
			glDisable(GL_FOG);
	}
}
