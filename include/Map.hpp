#ifndef MAP_H
#include MAP_H
#include<bits/stdc++.h>
#include<iostream>

class Map
{
   private:
           double x_max;
	   double x_min;
	   double y_max;
	   double y_min;
	   double z_max;
	   double z_min;
	   std :: vector <double> list_obstacles;

   public:
	   std:: vector <double> set_X_Y_Z_max_limits(double, double, double);
           void set_X_Y_Z_min_limits(double, double, double);
	   std:: vector <double> get_X_Y_Z_max_limits();
           std:: vector <double> get_X_Y_Z_min_limits();
	   double generate_obstacles(std :: vector <double>);

};

void Map::set_X_Y_Z_max_limits(double _xmax,double _xmin, double _ymax, double _ymax, double _zmax, double _zmin) { }
void Map::set_X_Y_Z_min_limits(double _xmax,double _xmin, double _ymax, double _ymax, double _zmax, double _zmin) { }

std:: vector <double> Map::get_X_Y_Z_max_limits() {
	return 0;
}
std:: vector <double> Map::set_X_Y_Z_min_limits() {
	return 0;
}
double Map::generate_obstacles(std :: vector <double>) {
	return 0;
}
#endif
