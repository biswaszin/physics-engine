#include <bits/stdc++.h>
#include <string.h>
#include <math.h>

// --------------------- VECTORS --------------------------
struct Vector{ 
    float x{};
    float y{};
}; 

// to add any two vector
Vector add(Vector a, Vector b){ 
    return {a.x + b.x, a.y + b.y};
}

// to subtract the vector
Vector substract(Vector a, Vector b){
    return {a.x - b.x, a.y - b.y};
}

// to multiply vector with any scalar quantity
Vector multiply(Vector c, float t){
    return {c.x*t, c.y*t};
}

// ---------------- ALIASES ------------------------------
using s32 = int32_t;  
using s64 = int64_t;
using u32 = uint32_t; // can be used on mass as mass can never be negative
using u64 = uint64_t; // same here


// --------------------- PARTICLE ------------------------
class Body{
private:
    float mass{1.0f}; // any particle to exist in this universe will have it's own mass
    Vector velocity{}; 
    Vector position{};
    Vector acceleration{};
public:

    // default constructor
    Body(float m = 1.0f, Vector v = {0,0}, Vector p = {0,0})
        : mass{m}, velocity{v}, position{p}
    {
        std::cout << "Particle is set.\n";
    }

    void setMass(){ // Setter for Mass of the particle
        std::cout << "Set the mass for the particle: \n";
        std::cin >> mass;
    }

    void setVectorPosition(){ // Setter for Position Vector
        std::cout << "Set the Vector Position\n";
        std::cout << "Enter the X,Y coordinate: ";
        std::cin >> position.x >> position.y;
    }

    void setVectorVelocity(){ // Setter for Velocity Vector
        std::cout << "Set the Vector Velocity\n";
        std::cout << "Enter the X,Y coordinate: ";
        std::cin >> velocity.x >> velocity.y;
    }

    // getter for mass
    float getMass() const { return mass; }

    // to get the acceleration of the body
    void applyForces(const Vector& givenForce){
        acceleration.x = givenForce.x / mass;
        acceleration.y = givenForce.y / mass; 
    }

    // to update everything
    void updateMotion(float dt){ 
        // v = u + at 
        velocity = add(velocity, multiply(acceleration, dt));

        // x' = x + vt
        position = add(position, multiply(velocity, dt));
    }

    void print() const{
        std::cout << "Position: (" << position.x << ", " << position.y << ")\n";
        std::cout << "Velocity: (" << velocity.x << ", " << velocity.y << ")\n";
        std::cout << "Acceleration: (" << acceleration.x << ", " << acceleration.y << ")\n";
    }
};

Vector setForce(){
    std::cout << "Force acting on the body X,Y : ";
    Vector temp;
    std::cin >> temp.x >> temp.y; 
    return temp;
}

// --------------------------- CONSTANTS ----------------------
const Vector gravityAcceleration = {0, -9.8f}; // default acceleration for any point in 2d space
const float dt = 1.0f; // time passed in real life, to be compiled in code


// to get the time from the user, and to get dt (delta time)
float SetDuration(){
    std::cout << "Enter t1: ";
    float t1{};
    std::cin >> t1;

    std::cout << "Enter t2: ";
    float t2{};
    std::cin >> t2; 

    return { t2-t1 }; 
}

// ------------------------- MAIN ----------------------------
int main(){
    
    
    Body ball{};
    ball.setMass();
    ball.setVectorPosition();
    ball.setVectorVelocity();
    Vector randomForce = setForce();
    float duration = SetDuration(); 
    
    // run the loop to get the updated velocity and position
    for (int i = 0; i < duration ; i++){

        ball.applyForces(randomForce); 
        ball.updateMotion(dt);

        std::cout << "Time at: " << i+1 << " seconds." << std::endl;
        ball.print(); // to print the position of the particle
        std::cout << "*----------------------------*\n";
    }
}

