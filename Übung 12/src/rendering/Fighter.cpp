/**
 * Fighter.cpp
 *
 */


#include "Fighter.hpp"
#include <algorithm>

namespace asteroids
{

void Fighter::shoot()
{
    // Create a new bullet with this fighter's position an x-Axis
	Bullet* b = new Bullet(m_position, m_xAxis);

	// Start a new thread, move the bullet
	b->start();

	// Add it to this fighter's vector of bullets
	m_bullets.push_back(b);
}
    
struct BulletRenderer
{
    void operator()(Bullet*& b)
    {
        b->render();
    }
};

struct BulletDeleter
{
    void operator()(Bullet*& b)
    {
        if(!b->isAlive())
        {
            delete b;
            b = NULL;
        }
    }
};
    
Fighter::Fighter()
{
    m_autopilot = false;
}
void Fighter::navigate(std::list<Vertex<float> > list)
{
    if(list.size())
    {
	// autopilot is on
	m_autopilot = true;
        
	// check-in the coordinates
	m_navigationList = list;
        
	// start the computer
	m_thread = std::thread(&Fighter::run, this);
    }
    cout << "No path to fly" << endl;
}
    
void Fighter::calculate(Vertex<float>  dest)
{
    // destination
    Vertex<float>  a = m_xAxis;
    Vertex<float>  b = dest - m_position;
    b.normalize();
        
    // cross product a x b
    Vertex<float>  axis = a.cross(b);
        
    //  a * b
    float numerator = a * b;
        
    // |a|
    float normA = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
        
    // |b|
    float normB = sqrt(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
        
    // |a| * |b|
    float denominator = normA * normB;
        
    //acos in Degree
    float angle = (acos(numerator/denominator));
        
    // Against the 'NaN's!
    if ((angle == angle) && (axis[0] == axis[0]) && (axis[1] == axis[1]) && (axis[2] == axis[2]))
    {
        rotate(axis, angle + PI);
    }
}
    
bool Fighter::getAutopilotState()
{
    // return the state of autopilot
    return m_autopilot;
}
    
    
void Fighter::run()
{
    // set the iteration at the beginning of the list
    m_iter = m_navigationList.begin();
        
    // get all coordinates
    while (m_iter != m_navigationList.end())
    {
        // not at the destination
        while(m_position.dist(*m_iter) > 10)
        {
            // calculate the new course
            calculate(*m_iter);
                
            // and fly
            move(STRAFE, -0.1);
      
            // (not to fast!)
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
        m_iter++;
    }
        
    // turn the autopilot off
    m_autopilot = false;
    //m_thread.join();
}


    
void Fighter::render()
{
    // Render the fighter
    TexturedMesh::render();
    /*vector<Bullet*>::iterator bulletIt;
    bulletIt = m_bullets.begin();
    // Iterate over the fighter's bullets and render them
    // if the bullet's lifetime is over, erase it from the vector.
    while(bulletIt != m_bullets.end()){
        (*bulletIt)->render();
        if(!(*bulletIt)->isAlive()){
            delete *bulletIt;
            bulletIt = m_bullets.erase(bulletIt);
	    }else{
	        bulletIt++;	
	    }
    } */
    
    //for_each(m_bullets.begin(), m_bullets.end(), BulletDeleter());
    list<Bullet*>::iterator new_end = remove(m_bullets.begin(), m_bullets.end(), static_cast<Bullet*>(NULL));
    m_bullets.erase(new_end, m_bullets.end());
    
    for_each(m_bullets.begin(), m_bullets.end(), BulletRenderer());
}

} // namespace asteroids
