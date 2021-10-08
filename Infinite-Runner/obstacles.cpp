#include <simplecpp>
#include <ctime>
#include <cassert>
#include <vector>
#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 400
#define OBSTACLE_MAX_H 100
#define OBSTACLE_W 100
#define GAP_OBSTACLES 300
#define GAP_OBSTACLE_COIN 200
#define GAP_COINS 400

class Obstacle
{

private:
    bool terrain_drawn;
    vector<Rectangle> upper;
    int num = 0;

public:
    void initTerrain();
    void initObstacles();
    void moveObstacles();
    bool check();

    friend class Coin;

};

bool Obstacle::check()
{
    for(int i = 0;i<num;i++)
    {
        int x = upper[i].getX();
        if(x<=538&&x>=466)
        {
            return true;
        }
    }
    return false;
}

void Obstacle ::initTerrain()
{
    terrain_drawn = true;
}

void Obstacle ::initObstacles()
{

    // assert(terrain_drawn);

    srand(time(0));
    double y, w, h;

    //if (i==0) x = START_OBSTACLE_X;
    //else if (x+OBSTACLE_W >= WINDOW_WIDTH) break;
    // x = randuv(10 * OBSTACLE_W, 15 * OBSTACLE_W);
    w = OBSTACLE_W;

    h = randuv(-OBSTACLE_MAX_H, OBSTACLE_MAX_H);

    if(abs(h)<20){
        if (h >= 0) h += 20;
        else if (h < 0) h -= 20;
    }

    y = WINDOW_HEIGHT - 110 - h / 2;

    if (num == 0)
    {
        Rectangle u(WINDOW_WIDTH, y, w, h);
        (h > 0) ? u.setColor(COLOR("red")) : u.setColor(COLOR("white"));
        u.setFill(true);
        upper.push_back(u);
        num++;
    }

    if (num > 0 && (WINDOW_WIDTH - upper[num - 1].getX() > GAP_OBSTACLES))
    {
        Rectangle u(WINDOW_WIDTH, y, w, h);
        (h > 0) ? u.setColor(COLOR("red")) : u.setColor(COLOR("white"));
        u.setFill(true);
        upper.push_back(u);
        num++;
    }

    /*
        double x1 = randuv (START_OBSTACLE_X, WINDOW_WIDTH);
        while (true) {
            x1 = randuv (x, WINDOW_WIDTH);
            if (x1-x > OBSTACLE_W/2) break;
        }
        x = x1;
*/
}

void Obstacle ::moveObstacles()
{
    for (int i = 0; i < num; i++)
    {
        upper[i].move(-20, 0);
    }
    if(!(upper.empty()))
    if(upper[0].getX() < 0&&!(upper.empty()))
    {
        upper.erase(upper.begin());
        num--;
    }
}
