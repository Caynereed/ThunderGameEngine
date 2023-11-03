#include "Thunder.h"

class Sandbox : public Thunder::Application
{
public:
	Sandbox() {};
	~Sandbox() {};

private:

};

Thunder::Application* Thunder::CreateApplication()
{
	return new Sandbox();
}