#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

float static pi = 3.141592653589;
float static g = 9.8;
float static m = 0.2;
float static mu = 0.7;
float static n = 1.0;
float norma (float vx, float vy);
float fx (float vx, float vy);
float fy (float vx, float vy);



int main(int argc, char const *argv[]) {
  float x=0;
  float y=0;
  float t_final = 3.0;
  float dt = 0.001;
  float tiempo = 0.0;
  float v0 = 10.0;
  float theta = 45.0;
  float vx= v0 * cos((theta*pi)/180.0) ;
  float vy = v0 * sin((theta*pi)/180.0);

  float kx1;
  float kx2;
  float kx3;
  float kx4;
  float kvx1;
  float kvx2;
  float kvx3;
  float kvx4;
  float ky1;
  float ky2;
  float ky3;
  float ky4;
  float kvy1;
  float kvy2;
  float kvy3;
  float kvy4;


  ofstream file;
  file.open("rk4.dat");
  file << tiempo << " " << x << " " << vx << " " << y <<" "<< vy << endl;

  while (tiempo < t_final) {
    kvx1 = dt * fx(vx,vy)/m;
    kvy1 = dt * (fy(vx,vy)/m - g);
    kx1 = dt * vx;
    ky1 = dt * vy;
    kvx2 = dt * fx(vx + kvx1 /2,vy)/m;
    kvy2 = dt * (fy(vx, vy + kvy1 /2)/m - g);
    kx2 = dt * (vx + kvx1/2);
    ky2 = dt * (vy + kvy1/2);
    kvx3 = dt * fx(vx + kvx2 /2,vy)/m;
    kvy3 = dt * (fy(vx, vy + kvy2 /2)/m - g);
    kx3 = dt * (vx + kvx2/2);
    ky3 = dt * (vy + kvy2/2);
    kvx4 = dt * fx(vx + kvx3,vy)/m;
    kvy4 = dt * (fy(vx, vy + kvy3)/m - g);
    kx4 = dt * (vx + kvx3);
    ky4 = dt * (vy + kvy3);

    vx = vx + (1.0/6.0) * (kvx1 + 2*kvx2 + 2*kvx3 + kvx4);
    vy = vy + (1.0/6.0) * (kvy1 + 2*kvy2 + 2*kvy3 + kvy4);
    x = x + (1.0/6.0) * (kx1 + 2*kx2 + 2*kx3 + kx4);
    y = y + (1.0/6.0) * (ky1 + 2*ky2 + 2*ky3 + ky4);

    tiempo = tiempo + dt;

    file << tiempo << " " << x << " " << vx << " " << y <<" "<< vy << endl;

  }

  file.close();
  return 0;
}

float norma (float vx, float vy){

  return sqrt(pow(vx,2)+ pow(vy,2));
}
float fx (float vx, float vy){
  return (-mu) * (pow(vx,n)) * vx/norma(vx,vy);
}
float fy (float vx, float vy){
  return (-mu) * (pow(vy,n)) * vy/norma(vx,vy);
}
