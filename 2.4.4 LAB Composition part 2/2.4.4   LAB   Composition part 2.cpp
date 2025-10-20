#include <iostream>
#include <string>
using namespace std;

class Engine
{
private:
	string type;
public:
	Engine(string type);
	void print();
};

Engine::Engine(string type)
{
	this->type = type;
}

void Engine::print()
{
	cout << "Engine: " << type << endl;
}

class Wheel
{
private:
	string size;
public:
	Wheel(string size);
	void print();
};

Wheel::Wheel(string size)
{
	this->size = size;
}

void Wheel::print()
{
	cout << "Wheel: " << size << endl;
}

class Chassis
{
private:
	string type;
public:
	Chassis(string type);
	void print();
};

Chassis::Chassis(string type)
{
	this->type = type;
}

void Chassis::print()
{
	cout << "Chassis: " << type << endl;
}

class Light
{
private:
	string type;
public:
	Light(string type);
	void print();
};

Light::Light(string type)
{
	this->type = type;
}

void Light::print()
{
	cout << "Light: " << type << endl;
}

class Body
{
private:
	string color;
public:
	Body(string color);
	void print();
};

Body::Body(string color)
{
	this->color = color;
}

void Body::print()
{
	cout << "Body: " << color << endl;
}

class Car
{
private:
	Engine* engine;
	Wheel* wheels[4];
	Chassis* chassis;
	Light* lights[10];
	Body* body;
public:
	Car(Engine* engine, Wheel* wheels[], Chassis* chassis, Light* lights[], Body* body);
	void print();
};

Car::Car(Engine* engine, Wheel* wheels[], Chassis* chassis, Light* lights[], Body* body)
{
	this->engine = engine;
	for (int i = 0; i < 4; i++)
	{
		this->wheels[i] = wheels[i];
	}
	this->chassis = chassis;
	for (int i = 0; i < 10; i++)
	{
		this->lights[i] = lights[i];
	}
	this->body = body;
}

void Car::print()
{
	engine->print();
	for (int i = 0; i < 4; i++)
	{
		wheels[i]->print();
	}
	chassis->print();
	for (int i = 0; i < 10; i++)
	{
		lights[i]->print();
	}
	body->print();
}

int main()
{
	Engine* engine = new Engine("1.0");

	Wheel* wheels[4];
	for (int i = 0; i < 4; i++)
	{
		wheels[i] = new Wheel("16inches");
	}

	Chassis* chassis = new Chassis("Normal");

	Light* lights[10];
	lights[0] = new Light("Type 1");
	lights[1] = new Light("Type 1");
	lights[2] = new Light("Type 2");
	lights[3] = new Light("Type 2");
	lights[4] = new Light("Type 3");
	lights[5] = new Light("Type 3");
	lights[6] = new Light("Type 4");
	lights[7] = new Light("Type 4");
	lights[8] = new Light("Type 5");
	lights[9] = new Light("Type 5");

	Body* body = new Body("Black");

	Car* car = new Car(engine, wheels, chassis, lights, body);

	car->print();

	return 0;
}