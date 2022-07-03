#include <iostream>
#include <cmath>

using namespace std;

static const double G = 6.67428e-11;
static const double AU = 149.6e6 * 1000;

class Nbody
{
	public:
		double mass;
		double x;
		double y;
		double xv;
		double yv;
	private:

		double force_x;
		double force_y;
		int timestep = 100;


	public:
		void force(Nbody other)
		{
			double obj_x, obj_y, obj_dist_x, obj_dist_y, dist, force, angle;
			obj_x = other.x;
			obj_y = other.y;

			obj_dist_x = obj_x - x;
			obj_dist_y = obj_y - y;

			dist = sqrt(obj_dist_x * obj_dist_x + obj_dist_y * obj_dist_y);
			force = G * mass * other.mass / (dist * dist);

			angle = atan2(obj_dist_y, obj_dist_x);

			force_x = cos(angle) * force;
			force_y = sin(angle) * force;


		};	    
		void position(Nbody bodies[])
		{
			double total_force_x, total_force_y;

			for (int i = 0; i < sizeof(bodies); i ++ ) 
			{
				total_force_x += force_x;
				total_force_y += force_y;

				xv = total_force_x / mass * timestep;
				yv = total_force_y / mass * timestep;

				x = xv * timestep;
				y = yv * timestep;
			}

		};

	
};

int main()
{
	Nbody earth;
	earth.mass = 5.9742e+24;

};